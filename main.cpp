#pragma once
#include <stdio.h>
#include <stdlib.h>

#include <vector>
#include <queue>

#include "src/Rendering/Renderer.h"
#include "src/Transforms.h"

#include "src/ECS/ecs.h"
#include "src/ECS/RenderComponent.h"

#include "src/ECS/world.h"

#define QUICK_Q(q) (TransformMatrix(q.front())); q.pop();

using ecs::world;

int main()
{
    initWorld(world);

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

    /* unsigned int shader = CreateShader("res/shader.shader");
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
    unsigned int ibo1 = CreateIndexBuffer(index, sizeof index); */

    std::queue<vec2> q;
    
    q.push({0, 0});
    q.push({-500.0f, 0.0f});
    q.push({500.0f, 0.0f});
    
    FrameBufferObject fbo = initFrameBuffer();
    
    using namespace std;
    vector<m4> matricies;


    for(int i = 0; i != 3; i++) { matricies.push_back QUICK_Q(q) }

    Entities entities;

    Entity entity, entity2, entity3;


    ecs::add<RenderComponent>(entity);
    ecs::add<RenderComponent>(entity2);
    ecs::add<RenderComponent>(entity3);
    
    entities.push_back(entity);
    entities.push_back(entity2);
    entities.push_back(entity3);

    CreateNewSquare(entity);
    CreateNewSquare(entity2, "res/Boris.png");
    CreateNewSquare(entity3);

    while(!glfwWindowShouldClose(window))
    {
        // Bind frame buffer here
        glBindFramebuffer(GL_FRAMEBUFFER, fbo.fbo);
        InitRenderLoop(window);

        // Updates the camera
        UpdateCamera();

        Draw(world.renderComponents, matricies, entities);

        // Draw all of the objects here
        //Render(vbo2, vao2, ibo, shader2, texture, matricies[2]);
        //Render(0, item.vao, item.ibo, item.shader, item.texture, matricies[0]);
        //Render(vbo, vao, ibo, shader, 0, matricies[0]);
        //Render(vbo1, vao1, ibo1, shader1, 0, matricies[1]);


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
