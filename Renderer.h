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

void InitRenderLoop(GLFWwindow* window);

void Render(unsigned int vbo, unsigned int vao, unsigned int ibo, unsigned int shader, unsigned short int texture);

void EndRenderLoop(GLFWwindow* window);

#endif
