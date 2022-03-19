#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <GLEW/glew.h>
#include <GLFW/glfw3.h>

#include <LCString/LCString.h>
#include <LCMaths/LCMaths.h>

#include "Shader.h"
#include "Texture.h"
#include "VertexBuffer.h"
#include "VertexArray.h"
#include "IndexBuffer.h"

#include "Shapes.h"
#include "Renderer.h"

unsigned int as = 0;
extern BuffersStuff bs;

float wid, high;
int x_angle = 0;
int y_angle = 0;
int z_angle = 0;

int kan = 0;

int Width_x, Height_y;

unsigned int stop = 0;

m4 proj;

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
    else if(key == GLFW_KEY_UP)
    {
        if(kan == 0)
            x_angle++;
        else if(kan == 1)
            y_angle++;
        else if(kan == 2)
            z_angle++;
    }
    else if(key == GLFW_KEY_ENTER)
    {
        printf("\n x: %d y: %d z: %d\n", x_angle, y_angle, z_angle);
        LogM4(proj);
        printf("\n");
    }
    else if(key == GLFW_KEY_DOWN)
    {
        if(kan == 0)
            x_angle--;
        else if(kan == 1)
            y_angle--;
        else if(kan == 2)
            z_angle--;
    }
    else if(key == GLFW_KEY_X)
    {
        kan = 0;
    }
    else if(key == GLFW_KEY_Y)
    {
        kan = 1;
    }
    else if(key == GLFW_KEY_Z)
    {
        kan = 2;
    }
    else if(key == GLFW_KEY_0)
    {
        x_angle = 0;
        y_angle = 0;
        z_angle = 0;
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

    Image("Face.png", -500);
    Square(1, 500);
    Triangle(0.25f, -500);

    proj = M4_Identity();
    m4 rx = M4_Identity();
    m4 ry = M4_Identity();
    m4 rz = M4_Identity();

    printf("\n");
    LogM4(proj);

    m4 trns = M4_Identity();
    Transform(&trns, (vec3){500.0, 0.0, 0.0});
    Scale(&trns, (vec3){1.0, 1.0, 1.0});

    while(!glfwWindowShouldClose(window))
    {
        if(stop == 1)
            return 0;

        Rotate_X(&rx, x_angle);
        Rotate_Y(&ry, y_angle);
        Rotate_Z(&rz, z_angle);
        SetMatrix(&proj, Mul(trns, TotalRotation(rx, ry, rz)).matrix);

        SetUniformM4(bs.shaders[0], "U_Transform", proj);

        Render(window);
    }

    glfwTerminate();

    return 0;
}