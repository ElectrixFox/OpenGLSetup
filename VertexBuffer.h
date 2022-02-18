#ifndef VERTEX_BUFFER_H
#define VERTEX_BUFFER_H

#pragma once
#include <LCString/LCString.h>
#include <GLEW/glew.h>
#include <GLFW/glfw3.h>

// The vertices of the object and the sizeof them (their length (sizeof(verticies))).
unsigned int CreateVertexBuffer(float* vertices, int size);

// A more in depth and controlable version.
// - Vertices and their length.
// - The size of the vertices.
// - The index of the attribute in the layout. 
// - How many items are in the attribute.
// - How many items are in a full row.
// - How many items are before it. 
unsigned int CreateVertexBufferDepth(float* vertices, int size, int index, int m_len, int R_len, int Start);

// - The index of the attribute in the layout. 
// - How many items are in the attribute.
// - How many items are in a full row.
// - How many items are before it. 
void AddAttribute(int index, int m_len, int R_len, int Start);

#endif