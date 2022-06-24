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

#include "ecsTypes.h"


#define PRESENT 167902105;

void CreateNewSquare(World& world, Entity entity);
void CreateNewSquare(World& world, Entity entity, std::string Texture_FilePath);

void Draw(RenderComponents res, std::vector<m4> projs, std::vector<Entity> entities, int n = 0);

#endif
