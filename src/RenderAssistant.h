#ifndef RENDER_ASSISTANT
#define RENDER_ASSISTANT

#include <cstdio>
#include <cstdlib>
#include "PlatformBindings.h"

#define DEFAULT_VEC3 {0, 0, 0}
#define DEFAULT_VEC2 {0, 0}

// Need a hash table to assign all of the entity data acording to the entities key

// Gets an avaliable hash for the new entity
/* This will all be blocked together in memory. 
 * So if it is an array of the struct then the memory will be: 
 * | object 1 | object 2 | object 3 | object 4 | object 5 | etc...
 * Howerver if it contains arrays then the memory will look like:
 * | model array | vao array | ibo array | shader array | texture array |
 * So if it is like this then it can cycle through all the ibo's predictably therefore prefetching the data.
*/

#endif
