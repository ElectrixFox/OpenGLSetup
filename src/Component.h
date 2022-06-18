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
    static int i = 0;
    unsigned int ID = ++i;
    entity.ID = ID;

    return ID;
};

NEW_COMPONENT_MANAGER(Render_Component)

Render_Component_Manager Render_component_manager;


namespace ecs
{
    Render_Component_Manager Render_component_manager;

    template<typename T>
    void add(Entity& entity) { };

    template<>
    void add<Render_Component>(Entity& entity)
    {
        unsigned int ID = Hash(entity);

        Render_component_manager.Render_Components[ID];
    };

    template<typename T>
    T& get(Entity entity) { };

    template<>
    Render_Component& get<Render_Component>(Entity entity)
    {
        return Render_component_manager.Render_Components[entity.ID];
    };
};


#endif