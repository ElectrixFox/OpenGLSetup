#pragma once
#include <stdio.h>
#include <stdlib.h>

#include "src/Renderer.h"

#include "src/Transforms.h"
#include "src/HashTable.h"

#include "src/Primatives.h"

#include <vector>

int main()
{
    GLFWwindow* window = CreateWindow(960, 540, "Hello World!");
    InitialiseGraphics();

    initMatricies();

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

    InitTransforms();

    unsigned int shader = CreateShader("res/shader.shader");
    SetUniformM4(shader, "U_Transform", M4_Identity());
    SetUniform4f(shader, "U_Colour", 1.0, 0.0, 0.0, 1.0);

    unsigned int vao = CreateVertexArray();
    unsigned int vbo = CreateVertexBuffer(vertex, sizeof(vertex));
    unsigned int ibo = CreateIndexBuffer(index, sizeof index);

    unsigned int shader2 = CreateShader("res/texShader.shader");
    unsigned short int texture = CreateTexture("res/Boris.png");
    SetUniformM4(shader, "U_Transform", M4_Identity());
    SetUniform4f(shader, "U_Colour", 1.0, 0.0, 0.0, 1.0);

    SetUniform1i(shader, "U_Texture", 0);

    unsigned int vao2 = CreateVertexArray();
    unsigned int vbo2 = CreateVertexBufferDepth(vertex, sizeof(vertex), 0, 3, 5, 0);
    AddAttribute(1, 2, 5, 3);

    unsigned int shader1 = CreateShader("res/shader.shader");
    SetUniformM4(shader1, "U_Transform", M4_Identity());
    SetUniform4f(shader1, "U_Colour", 1.0, 0.5, 0.0, 1.0);

    unsigned int vao1 = CreateVertexArray();
    unsigned int vbo1 = CreateVertexBuffer(vertex, sizeof(vertex));
    unsigned int ibo1 = CreateIndexBuffer(index, sizeof index);

    vec2 p1 = {0.0f, 0.0f};
    vec2 p2 = {-500.0f, -200.0f};
    vec2 p3 = {500.0f, 200.0f};
    PushBack(p1);
    PushBack(p2);
    PushBack(p3);
    
    FrameBufferObject fbo = initFrameBuffer();
    
    using namespace std;
    vector<m4> matricies;

    m4 p1m = M4_Identity();
    m4 p2m = M4_Identity();
    m4 p3m = M4_Identity();

    TransformMatrix(&p1m, PopOff());
    TransformMatrix(&p2m, PopOff());
    TransformMatrix(&p3m, PopOff());
	
    matricies.push_back(p1m);
    matricies.push_back(p2m);
    matricies.push_back(p3m);

    initItems();
    CreateSquare();

    RenderItem item = GetItem();
    cout << "Item: " << item.vao << '\n';

    while(!glfwWindowShouldClose(window))
    {
        // Bind frame buffer here
        glBindFramebuffer(GL_FRAMEBUFFER, fbo.fbo);
        InitRenderLoop(window);
        // Updates the camera
        UpdateCamera();

        // Draw all of the objects here
        //Render(0, item[0], item[1], item[2], item[3], matricies[0]);

        Render(vbo, vao, ibo, shader, 0, matricies[0]);

        Render(vbo1, vao1, ibo1, shader1, 0, matricies[1]);

        Render(vbo2, vao2, ibo, shader2, texture, matricies[2]);

        // End the render loop here
        EndRenderLoop(window);

        // Bind and draw the FBO here
        DrawFBO(fbo.vao, fbo.shader, fbo.screen_texture);

        // Poll all the events and swap buffers here
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwTerminate();

    return 0;
}