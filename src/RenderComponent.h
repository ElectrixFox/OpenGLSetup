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

#define PRESENT 1//167902105;

// Component

void CreateNewSquare(World& world, RenderComponent& rendercomponent);
void CreateNewSquare(RenderComponent& rendercomponent, std::string Texture_FilePath);


#endif
