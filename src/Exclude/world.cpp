#include "world.h"


void ecs::InitialseWorld(LCEcs_world_p& World)
{
    World.e_table->entities = (unsigned int*)malloc(sizeof(unsigned int*) * 128); 
    

    World.vc_table.renderComponents = renderComponents;
}
