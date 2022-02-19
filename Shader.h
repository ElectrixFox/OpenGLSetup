#ifndef SHADER_H
#define SHADER_H

#pragma once
#include <LCString/LCString.h>
#include <LCMaths.h>

#include <GLEW/glew.h>
#include <GLFW/glfw3.h>

typedef struct ShaderSources
{
    const char* VertexSource;
    const char* FragmentSource;
} ShaderSources;

extern int Width_x, Height_y;

ShaderSources PharseShader(const LCstring FilePath);
unsigned int CreateShader(const LCstring FilePath);

void SetUniform4f(unsigned int program, LCstring name, float v1, float v2, float v3, float v4);
void SetUniform1i(unsigned int program, LCstring name, int value);
void SetUniformMat4(unsigned int program, LCstring name, float value[4][4]);
void SetUniformM4(unsigned int program, LCstring name, m4 value);

void TransformInWindow(m4* projection, vec3 transform);
void ScaleInWindow(m4* projection, vec3 Scale);

void UpdateProjection(unsigned int program, m4 pos, m4 scale);


#endif