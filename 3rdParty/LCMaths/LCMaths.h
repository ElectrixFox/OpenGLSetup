#ifndef LCMATHS_H
#define LCMATHS_H

#pragma once
#include <cstdio>
#include <cstdlib>
#include <cmath>

#include <math.h>
#define M_PI 3.14159265358979323846


typedef float vec4[4];
typedef float vec3[3];
typedef float vec2[2];
typedef struct m4 { vec4 matrix[4]; } m4;
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
