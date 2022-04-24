#ifndef BUFFER_H
#define BUFFER_H

#pragma once
#include "Include/GLEW/glew.h"
#include "Include/GLFW/glfw3.h"

typedef struct
{
	unsigned int vbo;		// 4 bytes
	unsigned int vao;		// 4 bytes
	unsigned int ibo;		// 4 bytes
	unsigned int shader;		// 4 bytes
	unsigned short int texture;	// 2 bytes 
} ObjectBuffers;



#endif
