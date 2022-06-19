#ifndef RENDER_COMPONENT_H
#define RENDER_COMPONENT_H

#pragma once
#include "PlatformBindings.h"
#include "RenderAssistant.h"

#include "Shader.h"
#include "IndexBuffer.h"

#include "Texture.h"

#include "VertexArray.h"
#include "VertexBuffer.h"

#define PRESENT 1//167902105;

// Component
struct Render_Components
{
    unsigned int* vaos;
    unsigned int* ibos;
    unsigned int* shaders;
    unsigned int* textures;
};

struct Render_Component
{
    unsigned int& vao;
    unsigned int& ibo;
    unsigned int& shader;
    unsigned int& texture;
};

// Systems

// Initialises all of the stuff in the components
void InitComponents(Render_Components& rendercomponents);

// Draw function (Draw for an individual asset)
//void Draw(Entity entity, m4 proj);

// Batch draw function (Should be mainly used)
//void Draw(Render_Components rendercomponents);

void CreateNewSquare(Render_Component& rendercomponent);
void CreateNewSquare(Render_Component& rendercomponent, std::string Texture_FilePath);


#endif
