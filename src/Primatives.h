#ifndef PRIMATIVES_H
#define PRIMATIVES_H

#pragma once

#include "Rendering/Shader.h"
#include "Rendering/IndexBuffer.h"

#include "Rendering/Texture.h"

#include "Rendering/VertexArray.h"
#include "Rendering/VertexBuffer.h"

#include <iostream>
#include "Queue.h"

typedef struct
{ 
    unsigned int vao; 
    unsigned int ibo; 
    unsigned int shader;
    unsigned short int texture; 
} RenderItem;

void initItems();

void AddItem(unsigned int vao, unsigned int ibo, unsigned int shader, unsigned short int texture = 0);
void AddItem(RenderItem& item);

RenderItem GetItem();

//Render_Component CreateSquare();
//void CreateSquare(std::string Texture_FilePath);

#endif 
