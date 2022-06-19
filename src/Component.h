#ifndef COMPONENT_H
#define COMPONENT_H

#pragma once
#include "RenderComponent.h"
#include "world.h"

// Access for the tables and hashing

namespace ecs
{
    extern unsigned int Hash(Entity& entity);
};

namespace ecs
{
    template<typename T>
    void add(Entity& entity) { };

    template<>
    inline void add<Render_Component>(Entity& entity)
    {
        unsigned int ID = ecs::Hash(entity);
        extern Render_Components render_components;
        
        render_components.ibos[ID] = 0;
        render_components.vaos[ID] = 0;
        render_components.shaders[ID] = 0;
        render_components.textures[ID] = 0;
    };

    template<typename T>
    T& get(Entity entity) { };

    template<>
    inline Render_Component& get<Render_Component>(Entity entity)
    {
        extern Render_Components render_components;
        return { render_components.ibos[entity.ID], render_components.vaos[entity.ID], render_components.shaders[entity.ID], render_components.textures[entity.ID] };
    };

};


#endif
