#ifndef ECSTYPES_H
#define ECSTYPES_H

#pragma once
#include "PlatformBindings.h"

struct Entity
{
    unsigned int EntityID;
};

typedef struct
{
    unsigned int* vaos;
    unsigned int* ibos;
    unsigned int* shaders;
    unsigned int* textures;

    unsigned int*& operator[](int i) 
    { 
        switch (i)
        {
            case 0:
                return vaos;
            case 1:
                return ibos;
            case 2:
                return shaders;
            case 3:
                return textures;
        }
    }

} RenderComponents;


typedef struct
{
    RenderComponents renderComponents;
} World;

typedef struct
{
    unsigned int vao;
    unsigned int ibo;
    unsigned int shader;
    unsigned int texture;
} RenderComponent;

#endif