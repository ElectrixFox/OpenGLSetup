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

int cr = 0;
vec3 crt = {0};
int crtc = 0;

int kan = 0;

int Width_x, Height_y;

unsigned int stop = 0;

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
        LogM4(View);
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
    else if(key == GLFW_KEY_W)
    {
        cr += 1;
    }
    else if(key == GLFW_KEY_S)
    {
        cr -= 1;
    }
    else if(key == GLFW_KEY_A)
    {
        crt[crtc] += 1;
    }
    else if(key == GLFW_KEY_D)
    {
        crt[crtc] -= 1;
    }
    else if(key == GLFW_KEY_1)
    {
        crtc = 0;
    }
    else if(key == GLFW_KEY_2)
    {
        crtc = 1;
    }
    else if(key == GLFW_KEY_3)
    {
        crtc = 2;
    }
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

    glfwSetKeyCallback(window, Callback);

    glewInit();

    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    MVP = M4_Identity();
    m4 Model = M4_Identity();
    View = M4_Identity();
    Projection = M4_Identity();
    
    Image("Face.png", (vec3){0, 0, 0}, (vec3){1, 1, 1});
    Square(1, (vec3){300, 300, 0}, (vec3){0.5, 0.5, 0.5});
    Triangle(0.25f, (vec3){500, 500, 0}, (vec3){1, 1, 1});



    m4 rot = M4_Identity();
    m4 rx = M4_Identity();
    m4 ry = M4_Identity();
    m4 rz = M4_Identity();

    printf("\n");
    LogM4(Projection);

    m4 trns = M4_Identity();
    Transform(&trns, (vec3){-500, -500, 0.0});
    Scale(&Model, (vec3){1.0, 1.0, 1.0});

    MVP = Mul(Mul(Model, View), Projection);

    while(!glfwWindowShouldClose(window))
    {
        if(stop == 1)
            return 0;
        
        if(kan == 0)
            rot = Rotation(rot, x_angle, (vec3){1.0f, 0.0f, 0.0f});
        else if(kan == 1)
            rot = Rotation(rot, y_angle, (vec3){0.0f, 1.0f, 0.0f});
        else if(kan == 2)
            rot = Rotation(rot, z_angle, (vec3){0.0f, 0.0f, 1.0f});
        
        View = Mul(Rotation(View, cr, (vec3){1.0f, 0.0f, 0.0f}), LookAt((vec3){1, 0, 0}, (vec3){0, 1, 0}, (vec3){0, 0, 1}, crt));


        SetMatrix(&Model, Mul(trns, rot).matrix);

        MVP = Mul(Mul(Model, View), Projection);

        SetUniformM4(bs.shaders[0], "U_Transform", MVP);

        Render(window);
    }

    glfwTerminate();

    return 0;
}
