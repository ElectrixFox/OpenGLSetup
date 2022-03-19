#ifndef LCMATHS_H
#define LCMATHS_H

#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef float vec4[4];
typedef float vec3[3];
typedef struct m4 { vec4 matrix[4]; } m4;
typedef vec4 matrixv4[4];

void LogM4(m4 p);

m4 Transform_OPENGL(m4 mat, vec3 pos);
m4 Scale_OPENGL(m4 mat, vec3 Scale);

void SetMatrix(m4* set, matrixv4 as);

m4 Mul(m4 x, m4 y);

m4 M4_Identity();

#endif