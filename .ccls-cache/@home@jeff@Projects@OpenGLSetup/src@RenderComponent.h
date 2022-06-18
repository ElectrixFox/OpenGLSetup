#ifndef RENDER_COMPONENT_H
#define RENDER_COMPONENT_H

#pragma once
#include <memory>

#include "PlatformBindings.h"
#include "RenderAssistant.h"

#include "Shader.h"
#include "IndexBuffer.h"

#include "Texture.h"

#include "VertexArray.h"
#include "VertexBuffer.h"

#include "Component.h" 


#define PRESENT 1//167902105;

// Entity
typedef struct 
{
    int ID;
} Render_Entity;

// System

// Initialises all of the stuff in the components
void InitComponents(Render_Components& rendercomponents);

// Draw function (Draw for an individual asset)
void Draw(Entity entity, m4 proj);

// Batch draw function (Should be mainly used)
void Draw(Render_Components rendercomponents);

void CreateNewSquare(Render_Component& rendercomponent);
void CreateNewSquare(Render_Component& rendercomponent, std::string Texture_FilePath);


#endif
