#include <stdio.h>
#include <stdlib.h>

#include <vector>
#include <queue>

#include "src/Rendering/Renderer.h"
#include "src/Transforms.h"

#include "src/ECS/ecs.h"
#include "src/ECS/TransformComponent.h"
#include "src/ECS/RenderComponent.h"

#define QUICK_Q(q) (TransformMatrix(q.front())); q.pop();

int main()
{
    World world;

    initWorld(&world);
    ecs_register(world, Types::T_Render, struct RenderComponent);
    ecs_register(world, Types::T_Transform, struct TransformComponent);

    GLFWwindow* window = CreateWindow(960, 540, "Hello World!");
    InitialiseGraphics();

    initMatricies();

/* float vertex[] =
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
    unsigned int ibo1 = CreateIndexBuffer(index, sizeof index); */

    std::queue<vec2> q;
    
    q.push({0, 0});
    q.push({-500.0f, 0.0f});
    q.push({500.0f, 0.0f});

    TransformComponent trns_ent;
    trns_ent.position = {0.0f, 0.0f};
    trns_ent.rotation = {0.0f, 0.0f, 0.0f};
    trns_ent.scale = {1.0f, 1.0f};
    
    using namespace std;
    vector<m4> matricies;


    for(int i = 0; i != 3; i++) { matricies.push_back QUICK_Q(q) }
    q.empty();

    LC_LogM4(matricies[2]);

    vector<Entity> entities;

    Entity entity, entity2, entity3;
    entity.ID = 0;
    entity2.ID = 1;
    entity3.ID = 2;
    
    entities.push_back(entity);
    entities.push_back(entity2);
    entities.push_back(entity3);

    CreateNewSquare(&world, entity);
    CreateNewSquare(&world, entity2, "res/Boris.png");
    CreateNewSquare(&world, entity3);

    Entity* Entities = (Entity*)malloc(sizeof(Entity) * 5);
    Entities[0] = entity;
    Entities[1] = entity2;
    Entities[2] = entity3;

    FrameBufferObject fbo = initFrameBuffer();

    TransformComponent trns_ent2 = { {-500.0f, 0.0f}, {1.0f, 1.0f}, {0.0f, 0.0f, 0.0f} };
    TransformComponent trns_ent3 = { {500.0f, 0.0f}, {1.0f, 1.0f}, {0.0f, 0.0f, 0.0f} };

    add<TransformComponent>(&world, entity, Types::T_Transform, trns_ent);
    add<TransformComponent>(&world, entity2, Types::T_Transform, trns_ent2);
    add<TransformComponent>(&world, entity3, Types::T_Transform, trns_ent3);

    initialise();

    while(!glfwWindowShouldClose(window))
    {
        // Bind frame buffer here
        glBindFramebuffer(GL_FRAMEBUFFER, fbo.fbo);
        InitRenderLoop(window);

        // Updates the camera
        UpdateCamera();

        RenderComponent* renderComponents = (RenderComponent*)malloc(sizeof(RenderComponent) * 5);   
        renderComponents = get_set<RenderComponent>(&world, Entities, Types::T_Render);

        //float z = glfwGetTime();
        //vec3 rotation = {0.0f, 0.0f, z};
        //Rotate(&world, entity, rotation);

        //matricies[0] = RotateMaxtrix(get<TransformComponent>(&world, entity, Types::T_Transform)->rotation);

        TransformComponent* transformComponents =  (TransformComponent*)malloc(sizeof(TransformComponent) * 5);   
        transformComponents = get_set<TransformComponent>(&world, Entities, Types::T_Transform);

        Transform_Update(transformComponents, Entities, entities.size());

        Draw(renderComponents, getMatricies(), entities);


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
