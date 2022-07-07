#include <stdio.h>
#include <stdlib.h>

#include <vector>
#include <queue>

#include "src/Rendering/Renderer.h"
#include "src/Transforms.h"

#include "src/ECS/ecs.h"
#include "src/ECS/TransformComponent.h"
#include "src/ECS/RenderComponent.h"
#include "src/ECS/ecsComponents.h"

#define QUICK_Q(q) (TransformMatrix(q.front())); q.pop();

int main()
{
    World world;
    
    initWorld(&world);
    init_ecs_internal(world);

    GLFWwindow* window = CreateWindow(960, 540, "Hello World!");
    InitialiseGraphics();
    initMatricies();
    
    using namespace std;

    Entity entity, entity2, entity3;

    entity = newEntity(&world);
    entity2 = newEntity(&world, 5);
    entity3 = newEntity(&world);

    CreateNewSquare(&world, entity);
    CreateNewSquare(&world, entity2, "res/Boris.png");
    CreateNewSquare(&world, entity3);

    FrameBufferObject fbo = initFrameBuffer();

    add<TransformComponent>(&world, entity2, Types::T_Transform, { {-500.0f, 0.0f}, {1.0f, 1.0f}, {0.0f, 0.0f, 0.0f} });
    add<TransformComponent>(&world, entity3, Types::T_Transform, { {500.0f, 0.0f}, {0.5f, 0.5f}, {0.0f, 0.0f, 0.0f} });
    add<TransformComponent>(&world, entity, Types::T_Transform, { {0.0f, 0.0f}, {1.0f, 1.0f}, {0.0f, 0.0f, 0.0f} });

    initialise();


    cout << "Does entity 1 have a render component: " << has<RenderComponent>(world, entity, Types::T_Render) << '\n';
    assert(0);


    while(!glfwWindowShouldClose(window))
    {
        // Bind frame buffer here
        glBindFramebuffer(GL_FRAMEBUFFER, fbo.fbo);
        InitRenderLoop(window);

        // Updates the camera
        UpdateCamera();


        RenderComponent* renderComponents = (RenderComponent*)malloc(sizeof(RenderComponent) * 5);
        renderComponents = get_set<RenderComponent>(&world, (Entity*)world.entities, Types::T_Render);

        TransformComponent* transformComponents =  (TransformComponent*)malloc(sizeof(TransformComponent) * 5);   
        transformComponents = get_set<TransformComponent>(&world, (Entity*)world.entities, Types::T_Transform);

        Transform_Update(transformComponents, (Entity*)world.entities, 3);

        Draw(renderComponents, getMatricies(), (Entity*)world.entities);


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
