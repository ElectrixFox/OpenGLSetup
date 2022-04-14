#ifndef RENDER_ASSISTANT
#define RENDER_ASSISTANT

#include <stdio.h>
#include <stdlib.h>
#include "Include/LCMaths/LCMaths.h"

#define DEFAULT_VEC3 {1, 1, 1}
typedef struct
{
	unsigned int vbo;
	unsigned int vao;
	unsigned int ibo;
	unsigned int shader;
	unsigned short int texture;
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
	size_t Size;
	TransformObject* TransformObjects; // 32 bytes
} ResourceManager;

typedef struct
{
	TransformObject transformObject;
	Buffer buffer;
} MeshObject;

typedef struct
{
	size_t Size;
	MeshObject* meshObjects;
} MeshManager;

void InitRenderInstance(RenderInstance* renderInstance);
void AddBuffer(Buffer buffer, RenderInstance* renderInstance);

void InitResourceManager(ResourceManager* resourceManager);
void AddResource(TransformObject resource, ResourceManager* resourceManager);

void InitMeshManager(MeshManager* meshManager);
void AddMesh(MeshObject meshObject, MeshManager* meshManager);
#endif
