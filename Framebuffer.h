#ifndef FRAMEBUFFER_H
#define FRAMEBUFFER_H

#pragma once
#include <stdio.h>
#include <stdlib.h>

#include "Include/GLEW/glew.h"
#include "Include/GLFW/glfw3.h"

unsigned int CreateFramebuffer();

unsigned int TextureAttachment();
unsigned int Renderbuffer();

#endif
