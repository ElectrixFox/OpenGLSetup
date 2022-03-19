#ifndef MATRIXFUNCTIONS_H
#define MATRIXFUNCTIONS_H
#pragma once
#include <LCMaths.h>

void Transform(m4* transform, vec3 pos)
{
    pos[0] /= 960;
    pos[1] /= 540;

    transform->matrix[0][3] += pos[0];
    transform->matrix[1][3] += pos[1];
    transform->matrix[2][3] += pos[2];
    transform->matrix[3][3] = 1;
}

void Scale(m4* scale, vec3 sf)
{
    scale->matrix[0][0] = sf[0];
    scale->matrix[1][1] = sf[1];
    scale->matrix[2][2] = sf[2];
    scale->matrix[3][3] = 1;
}

void Rotate_X(m4* Rotation, float degrees)
{
    Rotation->matrix[1][1] = cos(degrees);
    Rotation->matrix[1][2] = -sin(degrees);
    Rotation->matrix[2][1] = sin(degrees);
    Rotation->matrix[2][2] = cos(degrees);
}

void Rotate_Y(m4* Rotation, float degrees)
{
    Rotation->matrix[0][0] = cos(degrees);
    Rotation->matrix[0][2] = sin(degrees);
    Rotation->matrix[2][0] = -sin(degrees);
    Rotation->matrix[2][2] = cos(degrees);
}

void Rotate_Z(m4* Rotation, float degrees)
{
    Rotation->matrix[0][0] = cos(degrees);
    Rotation->matrix[0][1] = -sin(degrees);
    Rotation->matrix[1][0] = sin(degrees);
    Rotation->matrix[1][1] = cos(degrees);
}


#endif