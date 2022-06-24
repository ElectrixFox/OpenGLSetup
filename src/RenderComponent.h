#ifndef RENDER_COMPONENT_H
#define RENDER_COMPONENT_H

#pragma once
#include "PlatformBindings.h"
#include "RenderAssistant.h"

#include "Rendering/Shader.h"
#include "Rendering/IndexBuffer.h"

#include "Rendering/Texture.h"

#include "Rendering/VertexArray.h"
#include "Rendering/VertexBuffer.h"

#include "ecsTypes.h"
#include <vector>

#define PRESENT 167902105;

void CreateNewSquare(World& world, Entity entity);
void CreateNewSquare(World& world, Entity entity, std::string Texture_FilePath);

void Draw(RenderComponents res, std::vector<m4> projs, int n = 0);

#endif
