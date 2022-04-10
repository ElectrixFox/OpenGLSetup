#include "Renderer.h"
#include <stdio.h>

void Render(GLFWwindow* window, RenderInstance renderInstance)
{
    glClear(GL_COLOR_BUFFER_BIT);
    glClearColor(0.25f, 0.5f, 0.35f, 1.0f);

    int size = renderInstance.Size;
    Buffer* buffers = renderInstance.buffers;
    printf("size = %d\n", size);
    for (int i = 0; i < 1; i++)
    {
	Buffer temp = buffers[i];
	unsigned int ibo = temp.ibo, vbo = temp.vbo, vao = temp.vao, program = temp.shader;
	glUseProgram(program);

        glBindVertexArray(vao);

        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ibo);
        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
    }

    glfwSwapBuffers(window);
    glfwPollEvents();
}
