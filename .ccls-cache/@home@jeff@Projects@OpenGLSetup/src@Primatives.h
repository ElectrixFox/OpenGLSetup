#ifndef PRIMATIVES_H
#define PRIMATIVES_H

#include "Shader.h"
#include "IndexBuffer.h"

#include "Texture.h"

#include "VertexArray.h"
#include "VertexBuffer.h"

#include "Queue.h"

void AddItem(unsigned int vao, unsigned int ibo, unsigned int shader, unsigned short int texture);
unsigned int* GetItem();

void CreateSquare();


#endif 
