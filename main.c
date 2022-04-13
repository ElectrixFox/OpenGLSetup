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

int x_angle = 0;
int y_angle = 0;
int z_angle = 0;

int cr = 0;
vec3 crt = {0};
int crtc = 0;

vec2 display;

m4 Projection;
m4 View;
m4 MVP;

GLFWwindow* CreateWindow(int width, int height, char* title)
{
    int Width_x, Height_y;
    GLFWwindow* window = glfwCreateWindow(width, height, title, 0, 0);
    glfwMakeContextCurrent(window);

    glfwGetWindowSize(window, &Width_x, &Height_y);
    display[0] = Width_x, display[1] = Height_y;

    return window;
}

int main()
{
    glfwInit();

    GLFWwindow* window = CreateWindow(960, 540, "Hello World!");

    glewInit();

    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    MVP = M4_Identity();
    m4 Model = M4_Identity();
    View = M4_Identity();
    Projection = M4_Identity();

    TransformObject* TransformObjects = malloc(sizeof(TransformObject) * 2);

    m4* transforms = malloc(sizeof(m4*) * 128);

    Buffer image = Image("Face.png", (vec3){0, 0, 0}, (vec3){1, 1, 1});
    Buffer square = Square(1, (vec3){300, 300, 0}, (vec3){0.5, 0.5, 0.5});
    Buffer triangle = Triangle(0.25f, (vec3){500, 500, 0}, (vec3){1, 1, 1});

    m4 rot = M4_Identity();
    m4 rx = M4_Identity();
    m4 ry = M4_Identity();
    m4 rz = M4_Identity();

    RenderInstance rI;
    InitRenderInstance(&rI);

    ResourceManager rM;
    InitResourceManager(&rM);

    AddBuffer(square, &rI);
    AddBuffer(image, &rI);
    AddBuffer(triangle, &rI);

    // Here is where we need to test the new transforming.
    // To-Do: Re-write the rotation because it is a little complex atm.
    m4 trns = M4_Identity();
    TransformMatrix(&trns, (vec3){1, 1, 1});

    while(!glfwWindowShouldClose(window))
    {
        //View = Mul(Rotation(View, cr, (vec3){1.0f, 0.0f, 0.0f}), LookAt((vec3){1, 0, 0}, (vec3){0, 1, 0}, (vec3){0, 0, 1}, crt));


        //SetMatrix(&Model, Mul(trns, rot).matrix);

        //MVP = Mul(Mul(Model, View), Projection);
	
	SetUniformM4(rI.buffers[1].shader, "U_Transform", trns);
        Render(window, rI);
    }

    glfwTerminate();

    return 0;
}
