#ifndef RENDER_COMPONENT_H
#define RENDER_COMPONENT_H

#pragma once
#include <vector>

#include "PlatformBindings.h"
#include "RenderAssistant.h"

#include "Rendering/Shader.h"
#include "Rendering/Texture.h"

#include "Rendering/IndexBuffer.h"

#include "Rendering/VertexArray.h"
#include "Rendering/VertexBuffer.h"

#include "ecs.h"

#define PRESENT 167902105;

struct RenderComponent
{
    unsigned int vao;
    unsigned int ibo;
    unsigned int shader;
    unsigned int texture;
    unsigned int vbo;
};
typedef struct RenderComponent RenderComponent;


void CreateNewSquare(World* world, Entity entity);
RenderComponent CreateNewSquare(World* world, Entity entity, int flags);
void CreateNewSquare(World* world, Entity entity, std::string Texture_FilePath);

// To-Do: Make the vertecies and indecies automatically find their sizes 
void Draw(RenderComponent* res, m4* projs, std::vector<Entity> entities, int vertex_size = 6, int indecies_size = 6);
void Draw(RenderComponent* res, std::vector<m4> projs, std::vector<Entity> entities);

#endif
