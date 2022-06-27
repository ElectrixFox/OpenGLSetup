#include "Renderer.h"
#include <stdio.h>

void InitialiseGraphics()
{
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glEnable(GL_DEPTH_TEST);
    glewInit();
}

void InitRenderLoop(GLFWwindow* window)
{
	glEnable(GL_DEPTH_TEST);

	glClearColor(0.25f, 0.5f, 0.35f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void Render(unsigned int vbo, unsigned int vao, unsigned int ibo, unsigned int shader, unsigned short int texture, m4 proj)
{ 
    extern m4 VP;

    m4 MVP = Mul(proj, VP);

    glBindTexture(GL_TEXTURE_2D, texture);

    glUseProgram(shader);
    SetUniformM4(shader, "U_Transform", MVP);

    glBindVertexArray(vao);

    if(ibo != 0)
    {
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ibo);
        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
    }

    glDrawArrays(GL_TRIANGLES, 0, 6);
}

void EndRenderLoop(GLFWwindow* window)
{
	glBindFramebuffer(GL_FRAMEBUFFER, 0);
	glDisable(GL_DEPTH_TEST);

	glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);
}
