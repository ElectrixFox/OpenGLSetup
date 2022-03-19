#ifndef RENDERER_H
#define RENDERER_H

#pragma once
#include <stdio.h>
#include <stdlib.h>

#include <Shader.h>
#include <Texture.h>

#include <VertexBuffer.h>
#include <VertexArray.h>

#include <IndexBuffer.h>

typedef struct BuffersStuff
{
    unsigned int* vbos;
    unsigned int* vaos;
    unsigned int* ibos;
    unsigned int* shaders;
    unsigned int* textures;
} BuffersStuff;

BuffersStuff bs;

extern unsigned int as;

void Render(GLFWwindow* window);

#endif