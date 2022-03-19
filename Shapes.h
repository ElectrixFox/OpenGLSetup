#ifndef SHAPES_H
#define SHAPES_H
#pragma once
#include <stdio.h>
#include <stdlib.h>

#include <Renderer.h>

extern BuffersStuff bs;
extern int as;

// Creates a square.
void Square(float cR, int trans);

// Creates a triangle.
void Triangle(float cR, int trans);

// Square with face.
void Image(const char* FilePath, int trans);



#endif