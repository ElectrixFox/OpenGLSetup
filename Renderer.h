#ifndef RENDERER_H
#define RENDERER_H

#pragma once
#include <stdio.h>
#include <stdlib.h>

#include "Shader.h"
#include "Texture.h"

#include "VertexBuffer.h"
#include "VertexArray.h"

#include "IndexBuffer.h"
#include "RenderAssistant.h"
#include "Shapes.h"

extern unsigned int as;
extern m4 View;
extern m4 Projection;

extern m4 VP;

void Render(GLFWwindow* window, MeshManager meshManager);

#endif
