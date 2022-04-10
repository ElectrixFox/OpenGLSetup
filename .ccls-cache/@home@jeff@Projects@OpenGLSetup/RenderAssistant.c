#pragma once
#include "RenderAssistant.h"


BuffersStuff bs;

ShapesData Shapes_Data;

void AddBuffer(Buffer buffer, RenderInstance* renderInstance)
{
	int size = (*renderInstance).Size;

	printf("Buffering Size: %d\n", size);
	renderInstance->buffers[0] = buffer;
	renderInstance->Size = size + 1;
}
