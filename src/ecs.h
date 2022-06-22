#ifndef ECS_H
#define ECS_H

#pragma once
#include "PlatformBindings.h"

// Entity
struct Entity
{
    unsigned int EntityID;
};

// Component
#include <vector>

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
    unsigned int& vao;
    unsigned int& ibo;
    unsigned int& shader;
    unsigned int& texture;
} RenderComponent;

namespace ecs
{
    template<typename Component>
    Component get(World world, Entity entity)
    {
        printf("Fail to choose type\n");
        assert(0);
    };

    template<>
    RenderComponent get<RenderComponent>(World world, Entity entity)
    {
        RenderComponent re = { world.renderComponents.vaos[entity.EntityID], world.renderComponents.ibos[entity.EntityID], world.renderComponents.shaders[entity.EntityID], world.renderComponents.textures[entity.EntityID] };
        return re;
    };
};

// Use bits to find if entity has component
// The size is incremented
// Then find the index using: ID % size of components array (array max size)
// That index is where the component is created or accessed
// This reduces waste space


// System


#endif