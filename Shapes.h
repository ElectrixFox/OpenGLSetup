#ifndef SHAPES_H
#define SHAPES_H
#pragma once
#include <stdio.h>
#include <stdlib.h>

#include "Shader.h"
#include "Texture.h"

#include "VertexBuffer.h"
#include "VertexArray.h"

#include "IndexBuffer.h"
#include "RenderAssistant.h"

// Creates a square.
Buffer Square(float cR, vec3 trans, vec3 scale);

// Creates a triangle.
Buffer Triangle(float cR, vec3 trans, vec3 scale);

// Square with face.
Buffer Image(const char* FilePath, vec3 trans, vec3 scale);

void SetArray(vec3* array, vec3 item, int index);



#endif
