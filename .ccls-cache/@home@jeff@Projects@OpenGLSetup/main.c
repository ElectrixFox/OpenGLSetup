#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <GLEW/glew.h>
#include <GLFW/glfw3.h>

#include <LCString/LCString.h>
#include <LCMaths/LCMaths.h>

#include "RenderAssistant.h"

#include "Shader.h"
#include "Texture.h"
#include "VertexBuffer.h"
#include "VertexArray.h"
#include "IndexBuffer.h"

#include "Shapes.h"
#include "Renderer.h"

#include "Framebuffer.h"

vec2 display;

m4 Projection;
m4 View;
m4 MVP;
m4 VP;

vec3 pos;

void Callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	if(key == GLFW_KEY_RIGHT && (action == GLFW_PRESS || action == GLFW_REPEAT))
	{
		pos[0] = pos[0] + 1;
	}
}

GLFWwindow* CreateWindow(int width, int height, char* title)
{
    int Width_x, Height_y;
    GLFWwindow* window = glfwCreateWindow(width, height, title, 0, 0);
    glfwMakeContextCurrent(window);

    glfwGetWindowSize(window, &Width_x, &Height_y);
    display[0] = Width_x, display[1] = Height_y;

    glfwSetKeyCallback(window, Callback);
    return window;
}

void Camera(m4* cam, vec3 position)
{
	ViewMatrix(cam, position);
}

int main()
{
    glfwInit();

    GLFWwindow* window = CreateWindow(960, 540, "Hello World!");

    glewInit();

    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glEnable(GL_DEPTH_TEST);



    MVP = M4_Identity();
    View = M4_Identity();
    Projection = M4_Identity();

    MeshObject image = Image("Face.png", (vec3){0, 0, 0}, (vec3){1, 1, 1});
    MeshObject image2 = Image("Boris.png", (vec3){-300, -100, 0}, (vec3){1, 1, 1});
    MeshObject square = Square(1, (vec3){300, 300, 0}, (vec3){1, 1, 1});
    MeshObject triangle = Triangle(0.25f, (vec3){500, 500, 0}, (vec3){1, 1, 1});

    MeshManager mM;
    InitMeshManager(&mM);

    AddMesh(square, &mM);
    AddMesh(image, &mM);
    AddMesh(triangle, &mM);
    AddMesh(image2, &mM);

    float vertices[] =
    {
        -1.0f,  1.0f,  0.0f, 1.0f,
        -1.0f, -1.0f,  0.0f, 0.0f,
         1.0f, -1.0f,  1.0f, 0.0f,

        -1.0f,  1.0f,  0.0f, 1.0f,
         1.0f, -1.0f,  1.0f, 0.0f,
         1.0f,  1.0f,  1.0f, 1.0f
    };

    unsigned int FboShader = CreateShader("FrameBuffer.shader");
    unsigned int Quadvao = CreateVertexArray();
    unsigned int Quadvbo = CreateVertexBufferDepth(vertices, sizeof vertices, 0, 2, 4, 0);
    AddAttribute(1, 2, 4, 2);
    glUseProgram(FboShader);
    SetUniform1i(FboShader, "screenTexture", 0);

    unsigned int fbo = CreateFramebuffer();
    unsigned int textureAttachment = TextureAttachment();
    unsigned int rbo = Renderbuffer();
    glBindFramebuffer(GL_FRAMEBUFFER, 0);  

    // To-Do: Re-write the rotation because it is a little complex atm.
    m4 trns = M4_Identity();
    TransformMatrix(&trns, (vec3){1, 1, 1});

    while(!glfwWindowShouldClose(window))
    {
	vec3 funnel = {pos[0], pos[1], pos[2]};
	Camera(&View, funnel);

	VP = Mul(View, Projection);


	glBindFramebuffer(GL_FRAMEBUFFER, fbo);
	glEnable(GL_DEPTH_TEST);
        Render(window, mM);
	glBindFramebuffer(GL_FRAMEBUFFER, 0);
	glDisable(GL_DEPTH_TEST);
	glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);

	glUseProgram(FboShader);
	glBindVertexArray(Quadvao);
	glBindTexture(GL_TEXTURE_2D, textureAttachment);
	glDrawArrays(GL_TRIANGLES, 0, 6);

	glfwSwapBuffers(window);
	glfwPollEvents();
    }

    glfwTerminate();

    return 0;
}
