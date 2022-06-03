#include "VertexArray.h"

unsigned int CreateVertexArray()
{
    unsigned int vao;
    glGenVertexArrays(1, &vao);
    glBindVertexArray(vao);

    return vao;
}
