#include "ecs.h"

void initWorld(World* world)
{
    Archetype*& archs = world->archetecture.archetypes;

    archs = (Archetype*)malloc(sizeof(Archetype) * 128);
    archs->components = (Component*)malloc(sizeof(Component) * 128);

    for (int i = 0; i < 128; i++)
    {
        archs->components[i].size = -1;
    }

    world->entities = (int*)malloc(sizeof(int) * 128);
    memset(world->entities, -1, 128);
}

void CreateArchetype(World* world, Types type, int size)
{
    Archetecture& arch = world->archetecture;

    arch.size++;
    arch.archetypes[type].type = type;
    arch.archetypes[type].size = 0;
    arch.archetypes[type].components = (Component*)malloc(sizeof(Component) * 128);
}

void Hash_Entity(int* entities, Entity& entity, int flags)
{
    static int i = 0;

bad:
    if(entities[i] != -1) 
        goto bad;
    
    entity.ID = i;

    i++;
    i += flags;
};