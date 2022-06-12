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


#include "../3rdParty/LCMaths/LCMaths.h"
#include "../3rdParty/LCString/LCString.h"

#include "../3rdParty/STB/stb_image.h"

#endif
