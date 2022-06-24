#ifndef SHADER_H
#define SHADER_H

#pragma once
#include "PlatformBindings.h"
#include <iostream>
#include <istream>

#include <string>

#include <sstream>
#include <fstream>

struct ShaderSources
{
    const std::string VertexSource;
    const std::string FragmentSource;
};

ShaderSources PharseShader(const LCstring FilePath);

unsigned int CreateShader(const LCstring FilePath);
unsigned int CreateShader(const char* VertexSource, const char* FragmentSource);

void SetUniform4f(unsigned int program, LCstring name, float v1, float v2, float v3, float v4);
void SetUniform1d(unsigned int program, LCstring name, int value);
void SetUniform1f(unsigned int program, LCstring name, float value);
void SetUniform1i(unsigned int program, LCstring name, int value);
void SetUniformMat4(unsigned int program, LCstring name, float value[4][4]);

void SetUniformM4(unsigned int program, LCstring name, m4 value);

void UpdateProjection(unsigned int program, char* name, m4 mvp);
void EasierUpdateProjection(unsigned int program, char* name, m4* mvp, m4 transform, m4 scale, m4 rotation);

#endif