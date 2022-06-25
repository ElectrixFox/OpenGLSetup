#include "world.h"

namespace ecs
{
    World world;
};

void initWorld(World& world) 
{
    world.renderComponents.renderComponents = (RenderComponent*)malloc(sizeof(unsigned int*) * 128);
}
