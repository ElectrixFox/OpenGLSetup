#include "Renderer.h"

void Render(GLFWwindow* window)
{
    glClear(GL_COLOR_BUFFER_BIT);
    glClearColor(0.25f, 0.5f, 0.35f, 1.0f);

    int lst = sizeof(bs.vaos) / sizeof(bs.vaos[0]);

    for (int i = 0; i < as+1; i++)
    {
        glUseProgram(bs.shaders[i]);

        //SetUniformM4(bs.shaders[i], "U_Transform", MVP);

        glBindVertexArray(bs.vaos[i]);

        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, bs.ibos[i]);
        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
    }

    glfwSwapBuffers(window);
    glfwPollEvents();
}
