#include "Component.h"

namespace ecs
{

    unsigned int Hash(Entity& entity)
    {
        unsigned int ID = rand() % 128;
        entity.ID = ID;

        return ID;
    };
}
