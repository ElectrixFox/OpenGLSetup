#include "LCMaths.h"

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
            result[i][j] = num;
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

m4 Transform(m4* transform, vec3 pos)
{
    pos[0] /= 960;
    pos[1] /= 540;

    transform->matrix[0][3] += pos[0];
    transform->matrix[1][3] += pos[1];
    transform->matrix[2][3] += pos[2];
    transform->matrix[3][3] = 1;

    return *transform;
}

m4 Scale(m4* scale, vec3 sf)
{
    scale->matrix[0][0] = sf[0];
    scale->matrix[1][1] = sf[1];
    scale->matrix[2][2] = sf[2];
    scale->matrix[3][3] = 1;

    return *scale;
}

m4 Rotation(m4 rotation, double angle, vec3 axis)
{
    static int ang;
    m4 proj = rotation;
    m4 rx = M4_Identity();
    m4 ry = M4_Identity();
    m4 rz = M4_Identity();

    /* {
        rx.matrix[1][1] = rotation.matrix[1][1];
        rx.matrix[1][2] = rotation.matrix[1][2];
        rx.matrix[2][1] = rotation.matrix[2][1];
        rx.matrix[2][2] = rotation.matrix[2][2];
    }

    {
        ry.matrix[0][0] = rotation.matrix[0][0];
        ry.matrix[0][2] = rotation.matrix[0][2];
        ry.matrix[2][0] = rotation.matrix[2][0];
        ry.matrix[2][2] = rotation.matrix[2][2];
    }

    {
        rz.matrix[0][0] = rotation.matrix[0][0];
        rz.matrix[0][1] = rotation.matrix[0][1];
        rz.matrix[1][0] = rotation.matrix[1][0];
        rz.matrix[1][1] = rotation.matrix[1][1]; 
    } */

    ang = angle;

    if(axis[0] == 1)
    {
        Rotate_X(&rx, angle);
    }
    else if (axis[1] == 1)
    {
        Rotate_Y(&ry, angle);
    }
    else if (axis[2] == 1)
    {
        Rotate_Z(&rz, angle);
    }

    proj = TotalRotation(rx, ry, rz);

    return proj;
}

m4 TotalRotation(m4 x, m4 y, m4 z)
{
    m4 total = M4_Identity();

    total = Mul(Mul(x, y), z);

    return total;
}

void Rotate_X(m4* Rotation, float degrees)
{
    double radians = degrees * (M_PI/180);
    
    Rotation->matrix[1][1] = cos(radians);
    Rotation->matrix[1][2] = -sin(radians);
    Rotation->matrix[2][1] = sin(radians);
    Rotation->matrix[2][2] = cos(radians);
}

void Rotate_Y(m4* Rotation, float degrees)
{
    double radians = degrees * (M_PI/180);

    Rotation->matrix[0][0] = cos(radians);
    Rotation->matrix[0][2] = sin(radians);
    Rotation->matrix[2][0] = -sin(radians);
    Rotation->matrix[2][2] = cos(radians);
}

void Rotate_Z(m4* Rotation, float degrees)
{
    double radians = degrees * (M_PI/180);

    Rotation->matrix[0][0] = cos(radians);
    Rotation->matrix[0][1] = -sin(radians);
    Rotation->matrix[1][0] = sin(radians);
    Rotation->matrix[1][1] = cos(radians);
}

m4 LookAt(vec3 V_Right, vec3 V_Up, vec3 V_Direction, vec3 V_Position)
{
    m4 lookAt = M4_Identity();

    m4 Normal = M4_Identity();

    vec4 matr[4] = { {V_Right[0], V_Right[1], V_Right[2], 0}, {V_Up[0], V_Up[1], V_Up[2], 0}, {V_Direction[0], V_Direction[1], V_Direction[2], 0}, {0, 0, 0, 1}};

    SetMatrix(&Normal, matr);

    m4 Camera = M4_Identity();

    vec4 matr2[4] = { {1, 0, 0, -V_Position[0]}, {0, 1, 0, -V_Position[1]}, {0, 0, 1, -V_Position[2]}, {0, 0, 0, 1}};
    SetMatrix(&Camera, matr2);


    lookAt = Mul(Normal, Camera);

    return lookAt;
};