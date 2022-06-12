#ifndef PRIMATIVES_H
#define PRIMATIVES_H

#include "Shader.h"
#include "IndexBuffer.h"

#include "Texture.h"

#include "VertexArray.h"
#include "VertexBuffer.h"

#include <iostream>
#include "Queue.h"

struct RenderItem
{ 
    unsigned int vao; 
    unsigned int ibo; 
    unsigned int shader;
    unsigned short int texture; 
};

void initItems();

void AddItem(unsigned int vao, unsigned int ibo, unsigned int shader, unsigned short int texture = 0);
RenderItem GetItem();

void CreateSquare();
void CreateSquare(std::string Texture_FilePath);

#endif 
