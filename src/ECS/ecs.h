#ifndef ECS_H
#define ECS_H

#pragma once
#include "PlatformBindings.h"
#include "ecsTypes.h"

namespace ecs
{
    template<typename Component>
    inline Component& get(Entity entity)
    {
        printf("Fail to choose type\n");
        assert(0);
    };

    template<>
    inline RenderComponent& get<RenderComponent>(Entity entity)
    {
        RenderComponent& re = renderComponents.renderComponents[entity.EntityID];
        return re;
    };

    template<>
    inline TransformComponent& get<TransformComponent>(Entity entity)
    {
        TransformComponent& tr = transformComponents.transformComponents[entity.EntityID];
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