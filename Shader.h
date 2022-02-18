#ifndef SHADER_H
#define SHADER_H

#pragma once
#include <LCString/LCString.h>
#include <GLEW/glew.h>
#include <GLFW/glfw3.h>

typedef struct ShaderSources
{
    const char* VertexSource;
    const char* FragmentSource;
} ShaderSources;

ShaderSources PharseShader(const LCstring FilePath);
unsigned int CreateShader(const LCstring FilePath);

void SetUniform4f(unsigned int program, LCstring name, float v1, float v2, float v3, float v4);
void SetUniform1i(unsigned int program, LCstring name, int value);
void SetUniformMat4(unsigned int program, LCstring name, float value[4][4]);

#endif