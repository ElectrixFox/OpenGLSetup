#ifndef RENDER_ASSISTANT
#define RENDER_ASSISTANT

#include <stdio.h>
#include <stdlib.h>
#include "Include/LCMaths/LCMaths.h"

typedef struct
{
	unsigned int vbo;
	unsigned int vao;
	unsigned int ibo;
	unsigned int shader;
} Buffer;

typedef struct
{
	size_t Size;
	Buffer* buffers;
} RenderInstance;



void InitRenderInstance(RenderInstance* renderInstance);

void AddBuffer(Buffer buffer, RenderInstance* renderInstance);

#endif
