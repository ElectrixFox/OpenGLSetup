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
	resourceManager->TransformObjects = malloc(sizeof(TransformObject) * 128);
}
