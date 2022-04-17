#ifndef RENDER_ASSISTANT
#define RENDER_ASSISTANT

#include <stdio.h>
#include <stdlib.h>
#include "Include/LCMaths/LCMaths.h"

#define DEFAULT_VEC3 {1, 1, 1}
typedef struct
{
	unsigned int vbo;		// 4 bytes
	unsigned int vao;		// 4 bytes
	unsigned int ibo;		// 4 bytes
	unsigned int shader;		// 4 bytes
	unsigned short int texture;	// 2 bytes 
} Buffer;

typedef struct
{
	vec2 position;		// 8 bytes
	vec3 rotation;		// 12 bytes
	vec3 scale;		// 12 bytes
} TransformObject;

typedef struct
{
	short int Size;			// 2 bytes
	TransformObject* TransformObjects;	// 32 bytes
} ResourceManager;

typedef struct
{
	TransformObject transformObject;	// 32 bytes
	Buffer buffer;				// 18 bytes
} MeshObject;

typedef struct
{
	short int Size;			// 2 bytes
	MeshObject* meshObjects;	// 50 bytes
} MeshManager;

typedef struct
{
	unsigned short int vao;
	unsigned short int shader; 
	unsigned short int texture;
} fboStruct;

typedef struct
{
	char FrameBuffer;	// 2 bytes
	fboStruct fbo;		// 6 bytes	
} RenderManager;


void InitRenderManager(RenderManager* renderManager);
void AddBuffer(Buffer buffer, RenderManager* renderManager);

void InitResourceManager(ResourceManager* resourceManager);
void AddResource(TransformObject resource, ResourceManager* resourceManager);

void InitMeshManager(MeshManager* meshManager);
void AddMesh(MeshObject meshObject, MeshManager* meshManager);
#endif
