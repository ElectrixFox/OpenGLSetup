#ifndef ECSTYPES_H
#define ECSTYPES_H

#pragma once
#include "PlatformBindings.h"
#include <vector>

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

struct Entities
{
    std::vector<Entity> entities;
    int size = 0;

    inline void push_back(Entity x) { entities.push_back(x); size++; };
};

typedef struct Entities Entities;

#endif