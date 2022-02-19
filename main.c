#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <GLEW/glew.h>
#include <GLFW/glfw3.h>

#include <LCString/LCString.h>
#include <LCMaths.h>

#include "Shader.h"
#include "Texture.h"
#include "VertexBuffer.h"
#include "VertexArray.h"
#include "IndexBuffer.h"

typedef struct BuffersStuff
{
    unsigned int* vbos;
    unsigned int* vaos;
    unsigned int* ibos;
    unsigned int* shaders;
    unsigned int* textures;
} BuffersStuff;

float wid, high;

int Width_x, Height_y;

GLFWwindow* CreateWindow(int width, int height, char* title)
{
    GLFWwindow* window = glfwCreateWindow(width, height, title, 0, 0);
    glfwMakeContextCurrent(window);

    glfwGetWindowSize(window, &Width_x, &Height_y);

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


    m4 trans = M4_Identity();
    m4 scale = M4_Identity();

    bs.vaos[0] = CreateVertexArray();
    bs.vbos[0] = CreateVertexBufferDepth(vertices, sizeof vertices, 0, 3, 5, 0);
    AddAttribute(1, 2, 5, 3);

    bs.textures[0] = CreateTexture("Face.png");
    bs.ibos[0] = CreateIndexBuffer(indecies, sizeof indecies);

    SetUniform4f(bs.shaders[0], "U_Colour", 1.0f, 0.5f, 0.2f, 1.0f);
    SetUniform1i(bs.shaders[0], "U_Texture", 0);

    TransformInWindow(&trans, (vec3){1, 0, 0});
    ScaleInWindow(&scale, (vec3){0.25f, 0.25f, 0.25f});

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, bs.ibos[0]);

    //LogM4(projection);

    while(!glfwWindowShouldClose(window))
    {
        glClear(GL_COLOR_BUFFER_BIT);
        glClearColor(0.25f, 0.5f, 0.35f, 1.0f);

        glUseProgram(bs.shaders[0]);
        glBindVertexArray(bs.vaos[0]);

        vec3 trns = {0, 0, 0};
        trns[0] = (float)glfwGetTime() * 5;

        TransformInWindow(&trans, trns);

        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

        glfwSwapBuffers(window);
        glfwPollEvents();

    }

    glfwTerminate();

    return 0;
}