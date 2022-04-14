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

    MVP = M4_Identity();
    m4 Model = M4_Identity();
    View = M4_Identity();
    Projection = M4_Identity();

    TransformObject* TransformObjects = malloc(sizeof(TransformObject) * 2);

    m4* transforms = malloc(sizeof(m4*) * 128);

    MeshObject image = Image("Face.png", (vec3){0, 0, 0}, (vec3){1, 1, 1});
    MeshObject square = Square(1, (vec3){300, 300, 0}, (vec3){1, 1, 1});
    MeshObject triangle = Triangle(0.25f, (vec3){500, 500, 0}, (vec3){1, 1, 1});

    RenderInstance rI;
    InitRenderInstance(&rI);

    ResourceManager rM;
    InitResourceManager(&rM);

    AddBuffer(square.buffer, &rI);
    AddBuffer(image.buffer, &rI);
    AddBuffer(triangle.buffer, &rI);

    MeshManager mM;
    InitMeshManager(&mM);

    AddMesh(square, &mM);
    AddMesh(image, &mM);
    AddMesh(triangle, &mM);
//    TransformObject img = {.position = {0}, .scale = DEFAULT_VEC3, .rotation = {0}};
//    TransformObject sqr = {.position = {300, 300}, .scale = DEFAULT_VEC3, .rotation = {0}};
//    TransformObject tri = {.position = {500, 500}, .scale = DEFAULT_VEC3, .rotation = {0}};

    AddResource(square.transformObject, &rM);
    AddResource(image.transformObject, &rM);
    AddResource(triangle.transformObject, &rM);

    // Here is where we need to test the new transforming.
    // To-Do: Re-write the rotation because it is a little complex atm.
    m4 trns = M4_Identity();
    TransformMatrix(&trns, (vec3){1, 1, 1});

    while(!glfwWindowShouldClose(window))
    {
	vec3 funnel = {pos[0], pos[1], pos[2]};
	Camera(&View, funnel);
//      MVP = Mul(Mul(Model, View), Projection);
//	SetUniformM4(rI.buffers[1].shader, "U_Transform", MVP);
	VP = Mul(View, Projection);
        Render(window, rI, rM);
    }

    glfwTerminate();

    return 0;
}
