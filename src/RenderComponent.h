#ifndef RENDER_COMPONENT_H
#define RENDER_COMPON_H

#pragma once
#include <memory>

#include "PlatformBindings.h"
#include "RenderAssistant.h"

#include "Shader.h"
#include "IndexBuffer.h"

#include "Texture.h"

#include "VertexArray.h"
#include "VertexBuffer.h"


#define PRESENT 1//167902105;

// Entity
typedef struct 
{
    int ID;
} Render_Entity;

// Component
struct Render_Components
{
    unsigned int* vaos;
    unsigned int* ibos;
    unsigned int* shaders;
    unsigned int* textures;
};

typedef struct
{
    unsigned int& vao; 
    unsigned int& ibo; 
    unsigned int& shader;
    unsigned int& texture; 
} Render_Component;


// System

// Initialises all of the stuff in the components
void InitComponents(Render_Components& rendercomponents);

// Need a hash table to assign all of the entity data acording to the entities key

// Gets an avaliable hash for the new entity
unsigned int Hash(Render_Components rendercomponents);

// Get from hash table
Render_Component getAsset(Render_Components rendercomponents, Entity entity);

// Add to the table
void addRenderComponent(Render_Components& rendercomponents, Entity& entity);
void addAsset(Render_Component rendercomponent);
void addAsset(unsigned int vao, unsigned int ibo, unsigned int shader, unsigned int texture = 0);

// Draw function (Draw for an individual asset)
void Draw(Render_Components rendercomponents, Entity entity, m4 proj);

// Batch draw function (Should be mainly used)
void Draw(Render_Components rendercomponents);

void CreateNewSquare(Render_Component& rendercomponent);

// Get render component function

// Get values


#endif