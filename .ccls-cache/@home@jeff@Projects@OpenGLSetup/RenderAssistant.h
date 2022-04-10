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

typedef struct ShapesData
{
    vec3* Transforms;
    vec3* Rotations;
    vec3* Scales;
} ShapesData;

typedef struct
{
	unsigned int vbo;
	unsigned int vao;
	unsigned int ibo;
	unsigned int shader;
} Buffer;

typedef struct
{
	unsigned int Size;
	Buffer* buffers;
} RenderInstance;

void AddBuffer(Buffer buffer, RenderInstance* renderInstance);
#endif
