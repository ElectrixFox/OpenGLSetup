#ifndef COMPONENT_H
#define COMPONENT_H

#pragma once
#include <iostream>
#include <memory>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "RenderComponent.h"
#include "RenderAssistant.h"

// Access for the tables and hashing
unsigned int Hash(Entity& entity)
{
    unsigned int ID = rand() % 128;
    entity.ID = ID;

    return ID;
};

NEW_COMPONENT_MANAGER(Render_Component)

namespace ecs
{
    template<typename T>
    void add(Entity& entity) { };

    template<>
    void add<Render_Component>(Entity& entity)
    {
        unsigned int ID = Hash(entity);
        extern Render_Component_Manager Render_component_manager;
        
        Render_component_manager.Render_Components[ID].ibo = 0;
        Render_component_manager.Render_Components[ID].vao = 0;
        Render_component_manager.Render_Components[ID].shader = 0;
        Render_component_manager.Render_Components[ID].texture = 0;
    };

    template<typename T>
    T& get(Entity entity) { };

    template<>
    Render_Component& get<Render_Component>(Entity entity)
    {
        extern Render_Component_Manager Render_component_manager;
        return Render_component_manager.Render_Components[entity.ID];
    };
};


#endif