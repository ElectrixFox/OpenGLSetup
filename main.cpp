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

    ecs_register(world, Types::T_Render, RenderComponent);
    ecs_register(world, Types::T_Transform, TransformComponent);

    GLFWwindow* window = CreateWindow(960, 540, "Hello World!");
    InitialiseGraphics();
    initMatricies();
    
    using namespace std;

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

    add<TransformComponent>(&world, entity2, Types::T_Transform, { {-500.0f, 0.0f}, {1.0f, 1.0f}, {0.0f, 0.0f, 0.0f} });
    add<TransformComponent>(&world, entity3, Types::T_Transform, { {500.0f, 0.0f}, {0.5f, 0.5f}, {0.0f, 0.0f, 0.0f} });
    add<TransformComponent>(&world, entity, Types::T_Transform, { {0.0f, 0.0f}, {1.0f, 1.0f}, {0.0f, 0.0f, 0.0f} });

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
