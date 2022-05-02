#ifndef RENDERER_H
#define RENDERER_H

#pragma once
#include <stdio.h>
#include <stdlib.h>

#include "RenderAssistant.h"
#include "WindowControls.h"
#include "Camera.h"

#include "Shader.h"
#include "Texture.h"

#include "VertexBuffer.h"
#include "VertexArray.h"

#include "IndexBuffer.h"
#include "Framebuffer.h"

void InitRenderLoop(GLFWwindow* window);

void Render(unsigned int vbo, unsigned int vao, unsigned int ibo, unsigned int shader, unsigned short int texture);

void EndRenderLoop(GLFWwindow* window);

#endif
