#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <GLEW/glew.h>
#include <GLFW/glfw3.h>

#include <LCString/LCString.h>
#include <LCMaths/LCMaths.h>

#include "RenderAssistant.h"

#include "Shader.h"
#include "Texture.h"
#include "VertexBuffer.h"
#include "VertexArray.h"
#include "IndexBuffer.h"

#include "Shapes.h"
#include "Renderer.h"

extern BuffersStuff bs;
unsigned int as = 0;

float wid, high;
int x_angle = 0;
int y_angle = 0;
int z_angle = 0;

int cr = 0;
vec3 crt = {0};
int crtc = 0;

int Width_x, Height_y;

m4 Projection;
m4 View;
m4 MVP;

GLFWwindow* CreateWindow(int width, int height, char* title)
{
    GLFWwindow* window = glfwCreateWindow(width, height, title, 0, 0);
    glfwMakeContextCurrent(window);

    glfwGetWindowSize(window, &Width_x, &Height_y);

    return window;
}

extern ShapesData Shapes_Data;

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

    glewInit();

    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    MVP = M4_Identity();
    m4 Model = M4_Identity();
    View = M4_Identity();
    Projection = M4_Identity();

    //Buffer image = Image("Face.png", (vec3){0, 0, 0}, (vec3){1, 1, 1});
    Buffer square = Square(1, (vec3){300, 300, 0}, (vec3){0.5, 0.5, 0.5});
    //Buffer triangle = Triangle(0.25f, (vec3){500, 500, 0}, (vec3){1, 1, 1});

    m4 rot = M4_Identity();
    m4 rx = M4_Identity();
    m4 ry = M4_Identity();
    m4 rz = M4_Identity();

    RenderInstance rI;

    rI.buffers = malloc(sizeof(Buffer) * 128);
    AddBuffer(square, &rI);
    //AddBuffer(image, rI);
    //AddBuffer(triangle, rI);

    //rI->buffers[0] = square;
    //rI->buffers[1] = image;
    //rI->buffers[2] = triangle;

    printf("\n");
    LogM4(Projection);

    m4 trns = M4_Identity();
    Transform(&trns, (vec3){-500, -500, 0.0});
    Scale(&Model, (vec3){1.0, 1.0, 1.0});

    MVP = Mul(Mul(Model, View), Projection);

    while(!glfwWindowShouldClose(window))
    {
        View = Mul(Rotation(View, cr, (vec3){1.0f, 0.0f, 0.0f}), LookAt((vec3){1, 0, 0}, (vec3){0, 1, 0}, (vec3){0, 0, 1}, crt));


        SetMatrix(&Model, Mul(trns, rot).matrix);

        MVP = Mul(Mul(Model, View), Projection);

        //SetUniformM4(bs.shaders[0], "U_Transform", MVP);

        Render(window, rI);
    }

    glfwTerminate();

    return 0;
}
