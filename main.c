#include <stdio.h>
#include <stdlib.h>
#include <GLEW/glew.h>
#include <GLFW/glfw3.h>

int main()
{
    printf("Hello World!");

    glfwInit();

    GLFWwindow* window = glfwCreateWindow(100, 100, "Test Window", NULL, NULL);
    glfwMakeContextCurrent(window);

    glewInit();

    while(!glfwWindowShouldClose(window))
    {
        glClear(GL_COLOR_BUFFER_BIT);

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwTerminate();

}