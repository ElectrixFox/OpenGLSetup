#include "Component.h"

namespace ecs
{
    Render_Component_Manager Render_component_manager;

    unsigned int Hash(Entity& entity)
    {
        unsigned int ID = rand() % 128;
        entity.ID = ID;

        return ID;
    };
}
