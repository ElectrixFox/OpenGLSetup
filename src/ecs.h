#ifndef ECS_H
#define ECS_H

#pragma once
#include "PlatformBindings.h"
#include "ecsTypes.h"

#define ECL_GET(world, entity) { world.renderComponents.vaos[entity.EntityID], world.renderComponents.ibos[entity.EntityID], world.renderComponents.shaders[entity.EntityID], world.renderComponents.textures[entity.EntityID] };

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
        //RenderComponent& re = { world.renderComponents.vaos[entity.EntityID], world.renderComponents.ibos[entity.EntityID], world.renderComponents.shaders[entity.EntityID], world.renderComponents.textures[entity.EntityID] };
        //RenderComponent& re = { world.renderComponents[0][entity.EntityID], world.renderComponents[1][entity.EntityID], world.renderComponents[2][entity.EntityID], world.renderComponents[3][entity.EntityID] };

        RenderComponent re = ECL_GET(world, entity);
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