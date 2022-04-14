#pragma once
#include "RenderAssistant.h"

void InitRenderInstance(RenderInstance* renderInstance)
{
	renderInstance->Size = 0;
	renderInstance->buffers = malloc(sizeof(Buffer) * 128);
}

void AddBuffer(Buffer buffer, RenderInstance* renderInstance)
{
	int size = (*renderInstance).Size;

	printf("Buffering Size: %d\n", size);
	renderInstance->buffers[size] = buffer;
	renderInstance->Size = size + 1;
}

void InitResourceManager(ResourceManager* resourceManager)
{
	resourceManager->Size = 0;
	resourceManager->TransformObjects = malloc(sizeof(TransformObject) * 128);
}


void AddResource(TransformObject resource, ResourceManager* resourceManager)
{
	int size = resourceManager->Size;

	printf("Transform Size: %d\n", size);
	resourceManager->TransformObjects[size] = resource;
	resourceManager->Size = size + 1;
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
