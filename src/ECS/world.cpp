#include "world.h"

void initWorld(World& world) 
{
    world.renderComponents.renderComponents = (RenderComponent*)malloc(sizeof(unsigned int*) * 128);
}
