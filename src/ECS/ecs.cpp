#include "ecs.h"

namespace ecs
{
    unsigned int Hash(Entity& entity)
    {
        unsigned int ID = rand() % 627318;

        entity.EntityID = ID;

        return ID;
    };
};