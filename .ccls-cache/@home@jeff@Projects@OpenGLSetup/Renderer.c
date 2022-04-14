#include "Renderer.h"
#include <stdio.h>

void Render(GLFWwindow* window, RenderInstance renderInstance, ResourceManager resourceManager)
{
    glClear(GL_COLOR_BUFFER_BIT);
    glClearColor(0.25f, 0.5f, 0.35f, 1.0f);

    int size = renderInstance.Size;
    Buffer* buffers = renderInstance.buffers;
    TransformObject* transobjs = resourceManager.TransformObjects;

    for (int i = 0; i < size; i++)
    {
	vec2 posi = {transobjs[i].position[0], transobjs[i].position[1]};
	m4 model = M4_Identity();
	TransformMatrix(&model, posi);
	printf("Position = %0.f, %0.f\n", posi[0], posi[1]);
	m4 MVP = Mul(model, VP);

	Buffer temp = buffers[i];
	unsigned int ibo = temp.ibo, vbo = temp.vbo, vao = temp.vao, program = temp.shader;

	glUseProgram(program);
	SetUniformM4(program, "U_Transform", MVP);

        glBindVertexArray(vao);

        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ibo);
        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
    }

    glfwSwapBuffers(window);
    glfwPollEvents();
}
