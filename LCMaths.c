#include "LCMaths.h"

m4 Transform_OPENGL(m4 mat, vec3 pos)
{
    m4 matrix = mat;

    matrix.matrix[0][3] += pos[0];
    matrix.matrix[1][3] += pos[1];
    matrix.matrix[2][3] += pos[2];

    return matrix;
};

m4 Scale_OPENGL(m4 mat, vec3 Scale)
{
    m4 matrix = mat;

    matrix.matrix[0][0] += Scale[0];
    matrix.matrix[1][1] += Scale[1];
    matrix.matrix[2][2] += Scale[2];

    return matrix;
}

void SetMatrix(m4* set, matrixv4 as)
{
    for (int y = 0; y < 4; y++)
        for (int x = 0; x < 4; x++)
            set->matrix[y][x] = as[y][x];
}

m4 Mul(m4 x, m4 y)
{
    m4 result = M4_Identity();

    for (int i = 0; i < 4; i++) 
    {
        for (int j = 0; j < 4; j++) {
            float num = 0;
            for (int k = 0; k < 4; k++) {
                num += x.matrix[i][k] * y.matrix[k][j];
            }
            result.matrix[i][j] = num;
        }
    }

    return result;
    
}

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

void LogM4(m4 p)
{
    for (int y = 0; y < 4; y++) 
    {
        for (int x = 0; x < 4; x++) 
            printf("%.2f ", p.matrix[y][x]); 
        printf("\n"); 
    }
}
