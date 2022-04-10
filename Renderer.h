#ifndef RENDERER_H
#define RENDERER_H

#pragma once
#include <stdio.h>
#include <stdlib.h>

#include "Shader.h"
#include "Texture.h"

#include "VertexBuffer.h"
#include "VertexArray.h"

#include "IndexBuffer.h"
#include "RenderAssistant.h"
#include "Shapes.h"

extern BuffersStuff bs;

extern unsigned int as;
extern ShapesData Shapes_Data;
extern m4 View;
extern m4 Projection;

void Render(GLFWwindow* window, RenderInstance renderInstance);

#endif
