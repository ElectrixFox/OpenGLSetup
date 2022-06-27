#ifndef LCMATHS_H
#define LCMATHS_H

#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <cmath>

#include <iostream>

#define M_PI 3.14159265358979323846

typedef struct 
{
    float x, y, z, w;

    float& operator [](int i) { switch (i) { case 0: return x;  case 1: return y;  case 2: return z;  case 3: return w; } return x; };
} vec4;

typedef struct { float x; float y; float z; float& operator [](int i) { switch (i) { case 0: return x;  case 1: return y;  case 2: return z; } return x; }; } vec3;
typedef struct { float x; float y;  float& operator [](int i) { switch (i) { case 0: return x;  case 1: return y;} return x;} } vec2;

typedef struct 
{ 
    vec4 matrix[4];
    vec4& operator [](int i) { return matrix[i]; }
} m4;

typedef vec4 matrixv4[4];

void LogM4(m4 p);

void SetMatrix(m4* set, matrixv4 as);

m4 Mul(m4 x, m4 y);

m4 M4_Identity();

m4 Transform(m4* transform, vec3 pos);
m4 Scale(m4* scale, vec3 sf);

m4 Rotation(m4 rotation, double angle, vec3 axis);

m4 TotalRotation(m4 x, m4 y, m4 z);

void Rotate_X(m4* Rotation, float degrees);
void Rotate_Y(m4* Rotation, float degrees);
void Rotate_Z(m4* Rotation, float degrees);

m4 LookAt(vec3 V_Right, vec3 V_Up, vec3 V_Direction, vec3 V_Position);

#endif
