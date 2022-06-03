#include "VertexBuffer.h"

unsigned int CreateVertexBuffer(float* vertices, int size) 
{
    unsigned int vbo;
    glGenBuffers(1, &vbo);
    glBindBuffer(GL_ARRAY_BUFFER, vbo);

    glBufferData(GL_ARRAY_BUFFER, size * sizeof(float), vertices, GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    return vbo;
}

// glVertexAttribPointer(index of layout, number of items in one, type of data, normalise?, the length of a row * sizeof(type), (void*)(how many items before it starts * sizeof(type))));
// glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)0);


unsigned int CreateVertexBufferDepth(float* vertices, int size, int index, int Attribute_len, int Row_len, int nItemsBefore)
{
    unsigned int vbo;
    glGenBuffers(1, &vbo);
    glBindBuffer(GL_ARRAY_BUFFER, vbo);

    glBufferData(GL_ARRAY_BUFFER, size * sizeof(float), vertices, GL_STATIC_DRAW);

    glVertexAttribPointer(index, Attribute_len, GL_FLOAT, GL_FALSE, Row_len * sizeof(float), (void*)(nItemsBefore * sizeof(float)));
    glEnableVertexAttribArray(index);

    return vbo;
}

void AddAttribute(int index, int Attribute_len, int Row_len, int nItemsBefore)
{
    glVertexAttribPointer(index, Attribute_len, GL_FLOAT, GL_FALSE, Row_len * sizeof(float), (void*)(nItemsBefore * sizeof(float)));
    glEnableVertexAttribArray(index);
}
