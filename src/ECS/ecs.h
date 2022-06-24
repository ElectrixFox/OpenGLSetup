#ifndef ECS_H
#define ECS_H

#pragma once
#include "PlatformBindings.h"
#include "ecsTypes.h"

#define ECL_GET(world, entity, type) { world.renderComponents.vaos[entity.EntityID], world.renderComponents.ibos[entity.EntityID], world.renderComponents.shaders[entity.EntityID], world.renderComponents.textures[entity.EntityID] };

namespace ecs
{
    template<typename Component>
    inline Component get(World world, Entity entity)
    {
        printf("Fail to choose type\n");
        assert(0);
    };

    template<>
    inline RenderComponent get<RenderComponent>(World world, Entity entity)
    {
        RenderComponent re = ECL_GET(world, entity);
        return re;
    };

    template<>
    inline TransformComponent get<TransformComponent>(World world, Entity entity)
    {
        TransformComponent tr = { world.transformComponents.positions[entity.EntityID], world.transformComponents.scales[entity.EntityID], world.transformComponents.rotations[entity.EntityID] };
        return tr;
    };
};

// Use bits to find if entity has component
// The size is incremented
// Then find the index using: ID % size of components array (array max size)
// That index is where the component is created or accessed
// This reduces waste space


// System


#endif