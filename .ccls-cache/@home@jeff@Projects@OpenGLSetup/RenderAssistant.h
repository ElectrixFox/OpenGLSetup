#ifndef RENDER_ASSISTANT
#define RENDER_ASSISTANT

#include <stdio.h>
#include <stdlib.h>
#include "Include/LCMaths/LCMaths.h"

typedef struct BuffersStuff
{
    unsigned int* vbos;
    unsigned int* vaos;
    unsigned int* ibos;
    unsigned int* shaders;
    unsigned int* textures;
} BuffersStuff;

extern BuffersStuff bs;

typedef struct ShapesData
{
    vec3* Transforms;
    vec3* Rotations;
    vec3* Scales;
} ShapesData;

extern ShapesData Shapes_Data;

#endif
