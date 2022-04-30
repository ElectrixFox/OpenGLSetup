#ifndef WINDOW_CONTROLS_H
#define WINDOW_CONTROLS_H

#pragma once
#include "Include/GLEW/glew.h"
#include "Include/GLFW/glfw3.h"

#include "Include/LCMaths/LCMaths.h"

GLFWwindow* CreateWindow(int width, int height, char* title);

void initMatricies();

#endif
