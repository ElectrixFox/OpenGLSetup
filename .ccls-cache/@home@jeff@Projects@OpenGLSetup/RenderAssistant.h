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

typedef struct
{
	vec2 position;
	vec3 rotation;
	vec3 scale;
} TransformObject;

typedef struct
{
	TransformObject* TransformObjects; // 32 bytes

} ResourceManager;

void InitRenderInstance(RenderInstance* renderInstance);

void AddBuffer(Buffer buffer, RenderInstance* renderInstance);

void InitResourceManager(ResourceManager* resourceManager);

#endif
