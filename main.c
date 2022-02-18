#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <GLEW/glew.h>
#include <GLFW/glfw3.h>

#include <LCString/LCString.h>
#include "Shader.h"
#include "Texture.h"
#include "VertexBuffer.h"

typedef struct BuffersStuff
{
    unsigned int* vbos;
    unsigned int* vaos;
    unsigned int* ibos;
    unsigned int* shaders;
    unsigned int* textures;
} BuffersStuff;

/* unsigned int CreateVBO(float* vertices, int size)
{
    unsigned int vbo;
    glGenBuffers(1, &vbo);
    glBindBuffer(GL_ARRAY_BUFFER, vbo);

    glBufferData(GL_ARRAY_BUFFER, size * sizeof(float), vertices, GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    return vbo;
} */

// glVertexAttribPointer(index of layout, number of items in one, type of data, normalise?, the length of a row * sizeof(type), (void*)(how many items before it starts * sizeof(type))));
// glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)0);


unsigned int CreateVAO()
{
    unsigned int vao;
    glGenVertexArrays(1, &vao);
    glBindVertexArray(vao);

    return vao;
}

unsigned int CreateIBO(unsigned int* indecies, int size)
{
    unsigned int ibo;
    glGenBuffers(1, &ibo);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ibo);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, size * sizeof(unsigned int), indecies, GL_STATIC_DRAW);

    return ibo;
}

GLFWwindow* CreateWindow(int width, int height, char* title)
{
    GLFWwindow* window = glfwCreateWindow(width, height, title, 0, 0);
    glfwMakeContextCurrent(window);

    return window;
}

int main()
{
    BuffersStuff bs;
    bs.vaos = malloc(sizeof(unsigned int*) * 128);
    bs.vbos = malloc(sizeof(unsigned int*) * 128);
    bs.ibos = malloc(sizeof(unsigned int*) * 128);
    bs.shaders = malloc(sizeof(unsigned int*) * 128);
    bs.textures = malloc(sizeof(unsigned int*) * 128);

    glfwInit();

    GLFWwindow* window = CreateWindow(960, 540, "Hello World!");

    glewInit();

    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    bs.shaders[0] = CreateShader("texShader.shader");

    float vertices[] = 
    {
        0.5f,  0.5f, 0.0f, 1.0f, 1.0f,
        0.5f, -0.5f, 0.0f, 1.0f, 0.0f,
       -0.5f, -0.5f, 0.0f, 0.0f, 0.0f,
       -0.5f,  0.5f, 0.0f, 0.0f, 1.0f
    };

    unsigned int indecies[] = 
    {
        0, 1, 3,
        1, 2, 3
    };


    bs.vaos[0] = CreateVAO();
    bs.vbos[0] = CreateVertexBufferDepth(vertices, sizeof vertices, 0, 3, 5, 0);
    AddAttribute(1, 2, 5, 3);

    bs.textures[0] = CreateTexture("Face.png");

    bs.ibos[0] = CreateIBO(indecies, sizeof indecies);

    SetUniform4f(bs.shaders[0], "U_Colour", 1.0f, 0.5f, 0.2f, 1.0f);
    SetUniform1i(bs.shaders[0], "U_Texture", 0);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, bs.ibos[0]);

    while(!glfwWindowShouldClose(window))
    {
        glClear(GL_COLOR_BUFFER_BIT);
        glClearColor(0.25f, 0.5f, 0.35f, 1.0f);

        glUseProgram(bs.shaders[0]);
        glBindVertexArray(bs.vaos[0]);
        
        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

        glfwSwapBuffers(window);
        glfwPollEvents();

    }

    glfwTerminate();

    return 0;
}