#ifndef SHAPES_H
#define SHAPES_H
#pragma once
#include <stdio.h>
#include <stdlib.h>

#include <Renderer.h>

extern BuffersStuff bs;
extern unsigned int as;

extern m4 Projection;

typedef struct ShapesData
{
    vec3 Transforms[128];
    vec3 Rotations[128];
    vec3 Scales[128];
} ShapesData;

ShapesData Shapes_Data;

// Creates a square.
void Square(float cR, vec3 trans, vec3 scale);

// Creates a triangle.
void Triangle(float cR, vec3 trans, vec3 scale);

// Square with face.
void Image(const char* FilePath, vec3 trans, vec3 scale);



#endif