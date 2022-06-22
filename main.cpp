#pragma once
#include <stdio.h>
#include <stdlib.h>

#include <vector>

#include "src/Rendering/Renderer.h"
#include "src/Transforms.h"

#include "src/Primatives.h"

#include "src/ecs.h"
#include "src/RenderComponent.h"

World world;

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

    PushBack({0, 0});
    PushBack({-500.0f, 0.0f});
    PushBack({500.0f, 0.0f});
    
    FrameBufferObject fbo = initFrameBuffer();
    
    using namespace std;
    vector<m4> matricies;

    m4 p1m = M4_Identity();
    m4 p2m = M4_Identity();
    m4 p3m = M4_Identity();

    TransformMatrix(p1m, PopOff());
    TransformMatrix(p2m, PopOff());
    TransformMatrix(p3m, PopOff());
	
    matricies.push_back(p1m);
    matricies.push_back(p2m);
    matricies.push_back(p3m);

    Entity entity;
    entity.EntityID = 0;

    world.renderComponents.ibos = (unsigned int*)malloc(sizeof(unsigned int*) * 128);
    world.renderComponents.ibos[0] = 20;
    world.renderComponents.vaos[0] = 20;
    world.renderComponents.shaders[0] = 20;
    world.renderComponents.textures[0] = 20;

    RenderComponent& re = ecs::get<RenderComponent>(world, entity);
    assert(0);

    CreateNewSquare(re);

    cout << re.ibo << '\n';


    while(!glfwWindowShouldClose(window))
    {
        // Bind frame buffer here
        glBindFramebuffer(GL_FRAMEBUFFER, fbo.fbo);
        InitRenderLoop(window);

        // Updates the camera
        UpdateCamera();

        //Draw(r_entity, matricies[0]);
        //Draw(n_entity, matricies[1]);

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
