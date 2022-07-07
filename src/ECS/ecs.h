#ifndef ECS_H
#define ECS_H

#include "PlatformBindings.h"
#include <stdarg.h>

/* Use bits to find if entity has component
The size is incremented
Then find the index using: ID % size of components array (array max size)
That index is where the component is created or accessed
This reduces waste space*/

enum Types
{
    T_Transform = 0,
    T_Render = 1,
};
typedef enum Types Types; 

struct Entity
{
    int ID;
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

    int* entities;
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

template<typename T>
inline void addr(World* world, int type, Entity entity, T component)
{
    Component& compy = world->archetecture.archetypes[type].components[entity.ID];
    world->archetecture.archetypes[type].size++;

    compy.size = sizeof(component);
    compy.data = malloc(compy.size);
    
    memcpy(compy.data, &component, sizeof(component));
};

#include <initializer_list>

template<typename C, typename... T>
inline void add_set(World* world, std::initializer_list<Types> type, Entity entity, C comp, T... comps)
{
    int size = type.size();
    Types ty[size];
    
    for(int i = 0; i < size; i++) 
        ty[i] = *((Types*)(type.begin() + i));
    
    
    addr(world, ty[0], entity, comp);

    for(int i = 1; i < size; i++) 
        addr(world, ty[i], entity, comps...);

};


// Add set 1:
template<typename T>
inline void add_setn(World* world, Types type, int size, ...)
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
};

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

// Used to check see if a component is present
template<typename T>
inline int has(World world, Entity entity, Types type)
{
    return (world.archetecture.archetypes[type].components[entity.ID].size == -1) ? 1 : 0;
};

// To-Do: Find a way to make the hash funciton useful performance wise
// Basic incremental hash for now
static inline int Hash_Entity(int* entities, int flags = 0)
{
    static int i = 0;

    // To-Do: Fix this
bad:
    if(entities[i] != -1) goto bad;

    i++;
    i += flags;

    return i;
};

// Overloaded function to change the entities ID value without having to return an int
void Hash_Entity(int* entities, Entity& entity, int flags = 0);

static inline void _addto_EntityList(int* entities, Entity e)
{
    entities[e.ID] = e.ID;
};

// Creates a new entity and returns it
static inline Entity newEntity(World* world, int flags = 0)
{
    Entity e;

    Hash_Entity((int*)world->entities, e, flags);

    _addto_EntityList(world->entities, e);

    std::cout << "Entity Number: " << e.ID << '\n';


    return e;
};

#define ecs_register(world, eType, type) CreateArchetype(&world, eType, sizeof(type))

#endif