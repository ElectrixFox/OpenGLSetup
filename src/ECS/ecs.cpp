#include "ecs.h"

void initWorld(World* world)
{
    Archetype*& archs = world->archetecture.archetypes;

    archs = (Archetype*)malloc(sizeof(Archetype) * 128);
    archs->components = (Component*)malloc(sizeof(Component) * 128);
}

void CreateArchetype(World* world, Types type, int size)
{
    Archetecture& arch = world->archetecture;

    arch.size++;
    arch.archetypes[type].type = type;
    arch.archetypes[type].size = 0;
    arch.archetypes[type].components = (Component*)malloc(sizeof(Component) * 128);
}