#ifndef ECS_H
#define ECS_H

#include "PlatformBindings.h"
#include <stdarg.h>

/* #pragma once
#include "PlatformBindings.h"
#include "ecsTypes.h"

#include "world.h"

namespace ecs
{   
    extern unsigned int Hash(Entity& entity);
};

namespace ecs
{
    template<typename Component>
    inline void add(Entity& entity) { };

    template<>
    inline void add<RenderComponent>(Entity& entity)
    {
        unsigned int ID = Hash(entity);

        extern World world;
        world.renderComponents.renderComponents[ID] = {0, 0, 0, 0};
    };

    template<typename Component>
    inline Component& get(Entity entity)
    {
        printf("Fail to choose type\n");
        assert(0);
    };

    template<>
    inline RenderComponent& get<RenderComponent>(Entity entity)
    {
        extern World world;
        RenderComponent& re = world.renderComponents.renderComponents[entity.EntityID];
        return re;
    };

    template<>
    inline TransformComponent& get<TransformComponent>(Entity entity)
    {
        TransformComponent& tr = world.transformComponents.transformComponents[entity.EntityID];
        return tr;
    };
};

// Use bits to find if entity has component
// The size is incremented
// Then find the index using: ID % size of components array (array max size)
// That index is where the component is created or accessed
// This reduces waste space


// System */

enum Types
{
    T_Transform = 0,
    T_Render = 1,
};
typedef enum Types Types; 

struct Entity
{
    unsigned int ID;
};
typedef struct Entity Entity;

struct Component
{
    void* data;
    int size;
};
typedef struct Component Component;

struct Archetype
{
    Types type;
    Component* components;
    int size;
};
typedef struct Archetype Archetype;

struct Archetecture
{
    Archetype* archetypes;
    int size;
};
typedef struct Archetecture Archetecture;

struct World
{
    Archetecture archetecture;
};
typedef struct World World;

void initWorld(World* world);
void CreateArchetype(World* world, Types type, int size);

template<typename T>
inline void add(World* world, Entity entity, Types type, T comp)
{
    Component& compy = world->archetecture.archetypes[type].components[entity.ID];
    world->archetecture.archetypes[type].size++;

    compy.size = sizeof(comp);
    compy.data = malloc(compy.size);

    memcpy(compy.data, &comp, sizeof(comp));
};

template<typename ...T>
inline void add_set(World* world, Types type, Entity entity, T... comps)
{
    std::vector<T...> types;

    (add<T>(world, entity, type, comps));
};


// Add set 1:
/*template<typename T>
inline void add_set(World* world, Types type, int size, ...)
{
    va_list args;
    va_start(args, size);

    int i = size;
    while(i --> 0)
    {
        Entity e = va_arg(args, Entity);
        T comp = va_arg(args, T);

        add<T>(world, e, type, comp);
    }
    
    va_end(args);
};*/

template<typename T>
inline T* get(World* world, Entity entity, Types type)
{
    T* object;
    object = (T*)world->archetecture.archetypes[type].components[entity.ID].data;

    return object;
};

template<typename T>
inline T* get_set(World* world, Entity* entities, Types type)
{
    T* objects = (T*)malloc(sizeof(T) * 128);

    Archetype arch = world->archetecture.archetypes[type];


    for(int i = 0; i < arch.size; i++)
    {
        memcpy((objects + i), arch.components[i].data, arch.components[i].size);
    }

    return objects;
};


#define ecs_register(world, eType, type) CreateArchetype(&world, eType, sizeof(type))

#endif