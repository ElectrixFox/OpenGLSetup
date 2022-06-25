#ifndef ECS_H
#define ECS_H

#pragma once
#include "PlatformBindings.h"
#include "ecsTypes.h"

#include "world.h"

#include <initializer_list>

namespace ecs
{
    extern World world;
    
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

    /* template<>
    inline TransformComponent& get<TransformComponent>(Entity entity)
    {
        TransformComponent& tr = world.transformComponents.transformComponents[entity.EntityID];
        return tr;
    }; */
};

// Use bits to find if entity has component
// The size is incremented
// Then find the index using: ID % size of components array (array max size)
// That index is where the component is created or accessed
// This reduces waste space


// System


#endif