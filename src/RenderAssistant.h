#ifndef RENDER_ASSISTANT
#define RENDER_ASSISTANT

#include <stdio.h>
#include <stdlib.h>
#include "PlatformBindings.h"

#define DEFAULT_VEC3 {1, 1, 1}

typedef struct
{
	vec2 position;		// 8 bytes
	vec3 rotation;		// 12 bytes
	vec3 scale;		// 12 bytes
} TransformObject;

#endif
