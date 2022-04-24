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

#include "Framebuffer.h"

vec2 display;

m4 Projection;
m4 View;
m4 MVP;
m4 VP;

vec3 pos;

void Callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	if(key == GLFW_KEY_RIGHT && (action == GLFW_PRESS || action == GLFW_REPEAT))
	{
		pos[0] = pos[0] + 1;
	}
}

GLFWwindow* CreateWindow(int width, int height, char* title)
{
    int Width_x, Height_y;
    GLFWwindow* window = glfwCreateWindow(width, height, title, 0, 0);
    glfwMakeContextCurrent(window);

    glfwGetWindowSize(window, &Width_x, &Height_y);
    display[0] = Width_x, display[1] = Height_y;

    glfwSetKeyCallback(window, Callback);
    return window;
}

void Camera(m4* cam, vec3 position)
{
	ViewMatrix(cam, position);
}

int main()
{
    glfwInit();

    GLFWwindow* window = CreateWindow(960, 540, "Hello World!");

    glewInit();

    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glEnable(GL_DEPTH_TEST);

    MVP = M4_Identity();
    View = M4_Identity();
    Projection = M4_Identity();

    float vertex[] =
    {
        0.5f,  0.5f, 0.0f, 1.0f, 1.0f,
        0.5f, -0.5f, 0.0f, 1.0f, 0.0f,
       -0.5f, -0.5f, 0.0f, 0.0f, 0.0f,
       -0.5f,  0.5f, 0.0f, 0.0f, 1.0f
    };

    unsigned int index[] =
    {
        0, 1, 3,
        1, 2, 3
    };

    float vertices[] =
    {
        -1.0f,  1.0f,  0.0f, 1.0f,
        -1.0f, -1.0f,  0.0f, 0.0f,
         1.0f, -1.0f,  1.0f, 0.0f,

        -1.0f,  1.0f,  0.0f, 1.0f,
         1.0f, -1.0f,  1.0f, 0.0f,
         1.0f,  1.0f,  1.0f, 1.0f
    };

    unsigned int shader = CreateShader("shader.shader");
    SetUniformM4(shader, "U_Transform", M4_Identity());
    SetUniform4f(shader, "U_Colour", 1.0, 0.0, 0.0, 1.0);

    unsigned int vao = CreateVertexArray();
    unsigned int vbo = CreateVertexBuffer(vertex, sizeof(vertex));
    unsigned int ibo = CreateIndexBuffer(index, sizeof index);

    unsigned int FboShader = CreateShader("FrameBuffer.shader");
    unsigned int Quadvao = CreateVertexArray();
    unsigned int Quadvbo = CreateVertexBufferDepth(vertices, sizeof vertices, 0, 2, 4, 0);
    AddAttribute(1, 2, 4, 2);
    glUseProgram(FboShader);
    SetUniform1i(FboShader, "screenTexture", 0);

    unsigned char fbo = CreateFramebuffer();
    unsigned int screen_texture = TextureAttachment();
    unsigned char rbo = Renderbuffer();
    glBindFramebuffer(GL_FRAMEBUFFER, 0);

    m4 trns = M4_Identity();
    TransformMatrix(&trns, (vec3){1, 1, 1});

    while(!glfwWindowShouldClose(window))
    {
        // Bind frame buffer here
        glBindFramebuffer(GL_FRAMEBUFFER, fbo);
        InitRenderLoop(window);

        vec3 funnel = {pos[0], pos[1], pos[2]};
        Camera(&View, funnel);

        VP = Mul(View, Projection);

        Render(vbo, vao, ibo, shader, 0);
        // Bind and draw the FBO here

        // End the render loop here
        EndRenderLoop(window);

        Render(0, Quadvao, 0, FboShader, screen_texture);

        // Poll all the events and swap buffers here.
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwTerminate();

    return 0;
}
