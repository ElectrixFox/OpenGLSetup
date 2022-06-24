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

    int size;

} RenderComponents;

typedef struct
{
    unsigned int& vao;
    unsigned int& ibo;
    unsigned int& shader;
    unsigned int& texture;
} RenderComponent;

typedef struct
{
    RenderComponents renderComponents;
} World;

inline void initWorld(World& world) 
{
    world.renderComponents.ibos = (unsigned int*)malloc(sizeof(unsigned int*) * 128);
    world.renderComponents.vaos = (unsigned int*)malloc(sizeof(unsigned int*) * 128);
    world.renderComponents.shaders = (unsigned int*)malloc(sizeof(unsigned int*) * 128);
    world.renderComponents.textures = (unsigned int*)malloc(sizeof(unsigned int*) * 128);
};

#endif