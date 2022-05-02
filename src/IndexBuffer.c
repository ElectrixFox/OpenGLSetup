#include "IndexBuffer.h"

unsigned int CreateIndexBuffer(unsigned int* indecies, int size)
{
    unsigned int ibo;
    glGenBuffers(1, &ibo);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ibo);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, size * sizeof(unsigned int), indecies, GL_STATIC_DRAW);

    return ibo;
}
