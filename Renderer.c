#include "Renderer.h"
#include <stdio.h>

void Render(GLFWwindow* window, MeshManager meshManager)
{
    glClear(GL_COLOR_BUFFER_BIT);
    glClearColor(0.25f, 0.5f, 0.35f, 1.0f);

    int size = renderInstance.Size;
    Buffer* buffers = renderInstance.buffers;
    TransformObject* transobjs = resourceManager.TransformObjects;

    for (int i = 0; i < size; i++)
    {
	m4 model = M4_Identity();

	// Change this so that it takes in 3 separate vectors not the objects as it could be more efficient and readable.
	model = InitialiseObjectTransforms(transobjs[i].position, transobjs[i].scale, transobjs[i].rotation);
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
