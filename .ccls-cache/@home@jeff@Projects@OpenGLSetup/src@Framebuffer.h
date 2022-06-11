#ifndef FRAMEBUFFER_H
#define FRAMEBUFFER_H

#pragma once
#include <cstdio>
#include <cstdlib>

#include "PlatformBindings.h"

#include "Shader.h"
#include "Texture.h"

#include "VertexBuffer.h"
#include "VertexArray.h"

#include "IndexBuffer.h"
#include "RenderAssistant.h"

unsigned int CreateFramebuffer();

unsigned int TextureAttachment();
unsigned int Renderbuffer();
#endif
