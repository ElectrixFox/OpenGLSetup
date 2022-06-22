#ifndef ECS_H
#define ECS_H

#pragma once
#include "PlatformBindings.h"
#include "ecsTypes.h"

namespace ecs
{
    template<typename Component>
    inline Component& get(World world, Entity entity)
    {
        printf("Fail to choose type\n");
        assert(0);
    };

    template<>
    inline RenderComponent& get<RenderComponent>(World world, Entity entity)
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