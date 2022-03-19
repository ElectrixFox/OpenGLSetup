#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <GLEW/glew.h>
#include <GLFW/glfw3.h>

#include <LCString/LCString.h>

#include "Shader.h"
#include "Texture.h"
#include "VertexBuffer.h"
#include "VertexArray.h"
#include "IndexBuffer.h"

#include "Shapes.h"
#include "Renderer.h"

extern BuffersStuff bs;
int as = 0;

float wid, high;

int Width_x, Height_y;

unsigned int stop = 0;

GLFWwindow* CreateWindow(int width, int height, char* title)
{
    GLFWwindow* window = glfwCreateWindow(width, height, title, 0, 0);
    glfwMakeContextCurrent(window);

    glfwGetWindowSize(window, &Width_x, &Height_y);

    return window;
}

int Callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    if(key == GLFW_KEY_SPACE)
    {
        stop = 1;
    }
}

int main()
{
    {
        bs.vaos = malloc(sizeof(unsigned int*) * 128);
        bs.vbos = malloc(sizeof(unsigned int*) * 128);
        bs.ibos = malloc(sizeof(unsigned int*) * 128);
        bs.shaders = malloc(sizeof(unsigned int*) * 128);
        bs.textures = malloc(sizeof(unsigned int*) * 128);
    }

    glfwInit();

    GLFWwindow* window = CreateWindow(960, 540, "Hello World!");

    glfwSetKeyCallback(window, Callback);

    glewInit();

    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    /* bs.shaders[0] = CreateShader("texShader.shader");

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

    bs.vaos[0] = CreateVertexArray();
    bs.vbos[0] = CreateVertexBufferDepth(vertices, sizeof vertices, 0, 3, 5, 0);
    AddAttribute(1, 2, 5, 3);

    bs.textures[0] = CreateTexture("Face.png");
    bs.ibos[0] = CreateIndexBuffer(indecies, sizeof indecies);

    SetUniform4f(bs.shaders[0], "U_Colour", 1.0f, 0.5f, 0.2f, 1.0f);
    SetUniform1i(bs.shaders[0], "U_Texture", 0);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, bs.ibos[0]); */

    Square(1, 500);
    Image("Face.png", -500);
    //Triangle(0.25f, -500);

    while(!glfwWindowShouldClose(window))
    {
        if(stop == 1)
            return 0;

        Render(window);
    }

    glfwTerminate();

    return 0;
}