#ifndef ECSCOMPONENTS_H
#define ECSCOMPONENTS_H

#include "RenderComponent.h"
#include "TransformComponent.h"

static inline void init_ecs_internal(World world)
{
    ecs_register(world, Types::T_Render, RenderComponent);
    ecs_register(world, Types::T_Transform, TransformComponent);
};

#endif