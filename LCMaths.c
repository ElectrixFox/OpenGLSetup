#include "LCMaths.h"

m4 Transform_OPENGL(m4 mat, vec3 pos)
{
    m4 matrix = mat;

    matrix.matrix[0][3] += pos[0];
    matrix.matrix[1][3] += pos[1];
    matrix.matrix[2][3] += pos[2];

    return matrix;
};

m4 M4_Identity()
{
    m4 identity = {0};

    float mtr[4][4] = 
    {
        { 1.0f, 0.0f, 0.0f, 0.0f },
        { 0.0f, 1.0f, 0.0f, 0.0f },
        { 0.0f, 0.0f, 1.0f, 0.0f },
        { 0.0f, 0.0f, 0.0f, 1.0f }
    };

    for (int y = 0; y < 4; y++)
        for (int x = 0; x < 4; x++)
            identity.matrix[y][x] = mtr[y][x];


    return identity;
}
