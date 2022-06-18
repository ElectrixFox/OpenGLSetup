#ifndef RENDER_ASSISTANT
#define RENDER_ASSISTANT

#include <cstdio>
#include <cstdlib>
#include "PlatformBindings.h"

#define DEFAULT_VEC3 {0, 0, 0}
#define DEFAULT_VEC2 {0, 0}

typedef struct
{
	vec2 position;		// 8 bytes
	vec3 rotation;		// 12 bytes
	vec3 scale;		    // 12 bytes
} TransformObject;


// Entity
typedef struct
{
    unsigned int ID;
} Entity;


#define NEW_COMPONENT_MANAGER(x) struct x##_Manager \
{ \
    x* x##s; \
}; \
 \
typedef struct x##_Manager ##x;

struct Render_Components
{
    unsigned int* vaos;
    unsigned int* ibos;
    unsigned int* shaders;
    unsigned int* textures;
};

typedef struct
{
    unsigned int vao; 
    unsigned int ibo; 
    unsigned int shader;
    unsigned int texture; 
} Render_Component;


typedef struct
{
	vec2 position;		// 8 bytes
	vec3 rotation;		// 12 bytes
	vec3 scale;		    // 12 bytes
} Transform_Component;

// Need a hash table to assign all of the entity data acording to the entities key

// Gets an avaliable hash for the new entity
/* This will all be blocked together in memory. 
 * So if it is an array of the struct then the memory will be: 
 * | object 1 | object 2 | object 3 | object 4 | object 5 | etc...
 * Howerver if it contains arrays then the memory will look like:
 * | model array | vao array | ibo array | shader array | texture array |
 * So if it is like this then it can cycle through all the ibo's predictably therefore prefetching the data.
*/

/*
typedef struct
{
    m4 model;               // 64 bytes
    unsigned int vao;       // 4 bytes
    unsigned int ibo;       // 4 bytes
    unsigned int shader;    // 4 bytes
    unsigned int texture;   // 4 bytes
} RenderItem;
*/

#endif
