#ifndef FRAMEBUFFER_H
#define FRAMEBUFFER_H

#pragma once
#include <stdio.h>
#include <stdlib.h>

#include "Include/GLEW/glew.h"
#include "Include/GLFW/glfw3.h"

#include "Shader.h"
#include "Texture.h"

#include "VertexBuffer.h"
#include "VertexArray.h"

#include "IndexBuffer.h"
#include "RenderAssistant.h"

unsigned int CreateFramebuffer();

unsigned int TextureAttachment();
unsigned int Renderbuffer();

RenderManager InitialiseFrameBuffer();
#endif
