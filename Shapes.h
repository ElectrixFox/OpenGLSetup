#ifndef SHAPES_H
#define SHAPES_H
#pragma once
#include <stdio.h>
#include <stdlib.h>

#include <Shader.h>
#include <Texture.h>

#include <VertexBuffer.h>
#include <VertexArray.h>

#include <IndexBuffer.h>
#include <RenderAssistant.h>

extern BuffersStuff bs;
extern unsigned int as;

extern m4 Projection;

extern ShapesData Shapes_Data;

// Creates a square.
void Square(float cR, vec3 trans, vec3 scale);

// Creates a triangle.
void Triangle(float cR, vec3 trans, vec3 scale);

// Square with face.
void Image(const char* FilePath, vec3 trans, vec3 scale);

void SetArray(vec3* array, vec3 item, int index);



#endif