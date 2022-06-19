#ifndef WORLD_H
#define WORLD_H

#pragma once
#include "PlatformBindings.h"

namespace ecs
{
    struct LCEcs_vital_component_table
    {
        // Insert all of the component masters/managers here:

    };

    struct LCEcs_entity_table
    {
        unsigned int* entities;
    };

    typedef struct LCEcs_entity_table LCEecs_entity_table;
    typedef struct LCEcs_vital_component_table LCEecs_vital_component_table;

    struct LCEcs_world_p
    {
        // Contains all of the entities
        LCEcs_entity_table* e_table;

        // Contains all of the components here
        LCEcs_vital_component_table* vc_table;

    };

    typedef struct LCEcs_world_p LCEcs_world_p;

    LCEcs_world_p& world;
};

#endif