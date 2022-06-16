#ifndef RENDER_COMPONENT_H
#define RENDER_COMPON_H

#include "PlatformBindings.h"

#include "Shader.h"
#include "IndexBuffer.h"

#include "Texture.h"

#include "VertexArray.h"
#include "VertexBuffer.h"
#include <memory>


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
//std::unique_ptr<Render_Component> getAsset(Render_Components rendercomponents, Render_Entity renderentity);
Render_Component getAsset(Render_Components rendercomponents, Render_Entity renderentity);

unsigned int& getIbo(Render_Components rendercomponents, Render_Entity renderentity);

// Add to the table
void addRenderComponent(Render_Components& rendercomponents, Render_Entity& renderentity);
void addAsset(Render_Component rendercomponent);
void addAsset(unsigned int vao, unsigned int ibo, unsigned int shader, unsigned int texture = 0);

// Draw function (Draw for an individual asset)
void Draw(Render_Components rendercomponents, Render_Entity renderentity);

// Batch draw function (Should be mainly used)
void Draw(Render_Components rendercomponents);

Render_Component* CreateNewSquare();

// Get render component function

// Get values


#endif