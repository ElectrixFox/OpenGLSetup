#pragma once
#include "RenderAssistant.h"

void InitRenderManager(RenderManager* renderManager)
{
//	renderManager->Size = 0;
//	renderManager->buffers = malloc(sizeof(Buffer) * 128);
}

void AddBuffer(Buffer buffer, RenderManager* renderManager)
{
//	int size = (*renderManager).Size;
//
//	printf("Buffering Size: %d\n", size);
//	renderManager->buffers[size] = buffer;
//	renderManager->Size = size + 1;
}

void InitResourceManager(ResourceManager* resourceManager)
{
//	resourceManager->Size = 0;
//	resourceManager->TransformObjects = malloc(sizeof(TransformObject) * 128);
}


void AddResource(TransformObject resource, ResourceManager* resourceManager)
{
//	int size = resourceManager->Size;
//
//	printf("Transform Size: %d\n", size);
//	resourceManager->TransformObjects[size] = resource;
//	resourceManager->Size = size + 1;
}

void InitMeshManager(MeshManager* meshManager)
{
	meshManager->Size = 0;
	meshManager->meshObjects = malloc(sizeof(MeshObject) * 128);
}

void AddMesh(MeshObject meshObject, MeshManager* meshManager)
{
	int size = meshManager->Size;

	printf("Mesh Size: %d\n", size);
	meshManager->meshObjects[size] = meshObject;
	meshManager->Size = size + 1;
}
