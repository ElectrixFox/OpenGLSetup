#ifndef LCMATHS_H
#define LCMATHS_H

#pragma once
#include <stdio.h>
#include <stdlib.h>

typedef float vec4[4];
typedef float vec3[3];
typedef struct m4 { vec4 matrix[4]; } m4;

m4 Transform_OPENGL(m4 mat, vec3 pos);

m4 M4_Identity();

#endif