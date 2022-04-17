#include "Renderer.h"
#include <stdio.h>

void Render(GLFWwindow* window, MeshManager meshManager, RenderManager renderManager)
{
	glBindFramebuffer(GL_FRAMEBUFFER, renderManager.FrameBuffer);
	glEnable(GL_DEPTH_TEST);

	glClearColor(0.25f, 0.5f, 0.35f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	int size = meshManager.Size;

	for (int i = 0; i < size; i++)
	{
		MeshObject mesh = meshManager.meshObjects[i];
		m4 model = M4_Identity();

		// Change this so that it takes in 3 separate vectors not the objects as it could be more efficient and readable.
		model = InitialiseObjectTransforms(mesh.transformObject.position, mesh.transformObject.scale, mesh.transformObject.rotation);
		m4 MVP = Mul(model, VP);

		Buffer temp = mesh.buffer;
		unsigned int ibo = temp.ibo, vbo = temp.vbo, vao = temp.vao, program = temp.shader;

		glBindTexture(GL_TEXTURE_2D, temp.texture);

		glUseProgram(program);
		SetUniformM4(program, "U_Transform", MVP);

		glBindVertexArray(vao);

		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ibo);
		glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
	}

	glBindFramebuffer(GL_FRAMEBUFFER, 0);
	glDisable(GL_DEPTH_TEST);

	glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);

	glUseProgram(renderManager.fbo.shader);
	glBindVertexArray(renderManager.fbo.vao);
	glBindTexture(GL_TEXTURE_2D, renderManager.fbo.texture);
	glDrawArrays(GL_TRIANGLES, 0, 6);

	glfwSwapBuffers(window);
	glfwPollEvents();
}
