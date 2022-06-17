#ifndef COMPONENT_H
#define COMPONENT_H

#include <iostream>
#include <memory>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Entity
typedef struct
{
    unsigned int ID;
} Entity;

struct Render_Component { unsigned int* ints; };
typedef struct Render_Component Render_Component;

// Access for the tables and hashing
unsigned int Hash(Entity& entity);

#define NEW_COMPONENT_MANAGER(x) typedef struct { ##x* x##; } x##_Manager;

NEW_COMPONENT_MANAGER(Render_Component);

namespace ecs
{
    Render_Component_Manager Render_component_manager;

    template<typename T>
    void add(Entity entity) { };

    template<>
    void add<Render_Component>(Entity entity)
    {
        unsigned int ID = Hash(entity);

        Render_component_manager.Render_Component[ID];
    };

    template<typename T>
    T& get(Entity entity) { };

    template<>
    Render_Component& get<Render_Component>(Entity entity)
    {
        return Render_component_manager.Render_Component[entity.ID];
    };
};


#endif