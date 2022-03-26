#ifndef RENDER_ASSISTANT
#define RENDER_ASSISTANT

#include <stdio.h>
#include <stdlib.h>
#include <LCMaths/LCMaths.h>

typedef struct BuffersStuff
{
    unsigned int* vbos;
    unsigned int* vaos;
    unsigned int* ibos;
    unsigned int* shaders;
    unsigned int* textures;
} BuffersStuff;

BuffersStuff bs;

typedef struct ShapesData
{
    vec3* Transforms;
    vec3* Rotations;
    vec3* Scales;
} ShapesData;

ShapesData Shapes_Data;

#endif