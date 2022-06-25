#ifndef WORLD_H
#define WORLD_H

#pragma once
#include "PlatformBindings.h"
#include "ecsTypes.h"

typedef struct
{
    RenderComponents renderComponents;
    TransformComponents transformComponents;
    
} World;

void initWorld(World& world);

#endif