#include "WindowControls.h"

vec2 display;

GLFWwindow* CreateWindow(int width, int height, const char* title)
{
    glfwInit();

    int Width_x, Height_y;
    GLFWwindow* window = glfwCreateWindow(width, height, title, 0, 0);
    glfwMakeContextCurrent(window);

    glfwGetWindowSize(window, &Width_x, &Height_y);
    display[0] = Width_x, display[1] = Height_y;


    return window;
}

