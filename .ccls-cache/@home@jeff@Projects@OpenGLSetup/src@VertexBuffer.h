#ifndef VERTEX_BUFFER_H
#define VERTEX_BUFFER_H

#pragma once
#include <LCString/LCString.h>
#include <GLEW/glew.h>
#include <GLFW/glfw3.h>

// The vertices of the object and the sizeof them (their length (sizeof(verticies))).
unsigned int CreateVertexBuffer(float* vertices, int size);

/** A more in depth and controlable version.
* @param vertices Vertices and their length.
* @param size The size of the vertices.
* @param index The index of the attribute in the layout. 
* @param m_len How many items are in the attribute.
* @param R_len How many items are in a full row.
* @param Start How many items are before it. 
*/
unsigned int CreateVertexBufferDepth(float* vertices, int size, int index, int m_len, int R_len, int Start);

/**
* @param index The index of the attribute in the layout. 
* @param m_len How many items are in the attribute.
* @param R_len How many items are in a full row.
* @param Start How many items are before it.
*/ 
void AddAttribute(int index, int m_len, int R_len, int Start);

#endif