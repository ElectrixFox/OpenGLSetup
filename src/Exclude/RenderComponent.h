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

void CreateNewSquare(Render_Component& rendercomponent);
void CreateNewSquare(Render_Component& rendercomponent, std::string Texture_FilePath);


#endif
