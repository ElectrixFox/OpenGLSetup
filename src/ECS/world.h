#ifndef WORLD_H
#define WORLD_H

#pragma once
#include "PlatformBindings.h"
#include "ecsTypes.h"

#include "Component.h"

typedef struct
{
    RenderComponents renderComponents;
    TransformComponents transformComponents;
    
} World;

namespace ecs
{
    extern World world;
};

void initWorld(World& world);

#endif