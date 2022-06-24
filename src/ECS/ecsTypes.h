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
    unsigned int vao;
    unsigned int ibo;
    unsigned int shader;
    unsigned int texture;
} RenderComponent;

typedef struct
{
    vec2 position;
    vec2 scale;
    vec3 rotation;
} TransformComponent;

typedef struct
{
    TransformComponent* transformComponents;
    int size;
} TransformComponents;

typedef struct
{
    RenderComponent* renderComponents;
    int size;

} RenderComponents;



typedef struct
{
    RenderComponents renderComponents;
    TransformComponents transformComponents;
    
} World;

inline void initWorld(World& world) 
{
    world.renderComponents.renderComponents = (RenderComponent*)malloc(sizeof(unsigned int*) * 128);
};

#endif