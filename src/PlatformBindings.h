#ifndef PLATFORM_BINDINGS_H
#define PLATFORM_BINDINGS_H

#pragma once

#ifndef _WIN32
#include "GL/glew.h"
#include "glfw3.h"
#else
#include "GLEW/glew.h"
#include "glfw3.h"
#endif

#ifdef __cplusplus
// Cpp headers to use cpp
#include <iostream>
#include <string>

#include <memory>

// C functions to maintain usage and ease of use
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#else
// So that any C files don't use cpp headers
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#endif

#include "../3rdParty/LCMaths/LCMaths.h"
#include "../3rdParty/LCString/LCString.h"

#include "../3rdParty/STB/stb_image.h"

#endif
