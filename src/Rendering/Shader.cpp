#include "Shader.h"

/* Shader sources
const char* VertexshaderSource = 
{
    "#version 430 core\n"
    "layout (location = 0) in vec3 aPos;\n"
    "void main()\n"
    "{\n"
    "   gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
    "}\0"
};

const char* FragmentshaderSource = 
{
    "#version 430 core\n"
    "out vec4 FragColour;\n"
    "void main()\n"
    "{\n"
    "   FragColour = vec4(1.0f, 0.5f, 0.2f, 1.0f);\n"
    "}\n\0"
}; */

ShaderSources PharseShader(const char* FilePath)
{
    using namespace std;

    ifstream file;
    file.open(FilePath);

    string line;

    stringstream ss[2];

    while(getline(file, line))
    {
        static int i = 0;

        if(line.find("#shader") != string::npos)
        {
            if(line.find("#shader Vertex") != string::npos)
            {
                i = 0;
            }
            else if(line.find("#shader Fragment") != string::npos)
            {
                i = 1;
            }
        }
        else
        {
            ss[i] << line << '\n';
        }

    }
    
    file.close();

    return {ss[0].str(), ss[1].str()};
}

unsigned int CreateShader(const char* FilePath)
{
    ShaderSources ss = PharseShader(FilePath);

    const char* VSS = ss.VertexSource.c_str();
    const char* FSS = ss.FragmentSource.c_str();

    unsigned int vS;
    vS = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vS, 1, &VSS, NULL);
    glCompileShader(vS);

    {
        int success;
        char infoLog[512];
        glGetShaderiv(vS, GL_COMPILE_STATUS, &success);

        if(!success)
        {
            glGetShaderInfoLog(vS, 512, NULL, infoLog);
            std::cout << "Vertex shader broken: " << infoLog << std::endl;
        }
    };


    unsigned int fS;
    fS = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fS, 1, &FSS, NULL);
    glCompileShader(fS);

    {
        int success;
        char infoLog[512];
        glGetShaderiv(fS, GL_COMPILE_STATUS, &success);

        if(!success)
        {
            glGetShaderInfoLog(fS, 512, NULL, infoLog);
            std::cout << "Fragment shader broken: " << infoLog << std::endl;
        }
    };

    unsigned int program;
    program = glCreateProgram();
    glAttachShader(program, vS);
    glAttachShader(program, fS);
    glLinkProgram(program);

    {
        int success;
        char infoLog[512];
        glGetProgramiv(program, GL_LINK_STATUS, &success);

        if(!success)
        {
            glGetProgramInfoLog(program, 512, NULL, infoLog);
            std::cout << "Program broken broken: " << infoLog << std::endl;
        }
    };

    glUseProgram(program);
    glDeleteShader(vS);
    glDeleteShader(fS);

    return program;
};

unsigned int CreateShader(const char* VertexSource, const char* FragmentSource)
{
    const char* VSS = VertexSource;
    const char* FSS = FragmentSource;

    unsigned int vS;
    vS = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vS, 1, &VSS, NULL);
    glCompileShader(vS);

    {
        int success;
        char infoLog[512];
        glGetShaderiv(vS, GL_COMPILE_STATUS, &success);

        if(!success)
        {
            glGetShaderInfoLog(vS, 512, NULL, infoLog);
            std::cout << "Vertex shader broken: " << infoLog << std::endl;
        }
    };


    unsigned int fS;
    fS = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fS, 1, &FSS, NULL);
    glCompileShader(fS);

    {
        int success;
        char infoLog[512];
        glGetShaderiv(fS, GL_COMPILE_STATUS, &success);

        if(!success)
        {
            glGetShaderInfoLog(fS, 512, NULL, infoLog);
            std::cout << "Fragment shader broken: " << infoLog << std::endl;
        }
    };

    unsigned int program;
    program = glCreateProgram();
    glAttachShader(program, vS);
    glAttachShader(program, fS);
    glLinkProgram(program);

    {
        int success;
        char infoLog[512];
        glGetProgramiv(program, GL_LINK_STATUS, &success);

        if(!success)
        {
            glGetProgramInfoLog(program, 512, NULL, infoLog);
            std::cout << "Program broken broken: " << infoLog << std::endl;
        }
    };

    glUseProgram(program);
    glDeleteShader(vS);
    glDeleteShader(fS);

    return program;
}

void SetUniform4f(unsigned int program, const char* name, float v1, float v2, float v3, float v4) 
{
    glUseProgram(program);
    glUniform4f(glGetUniformLocation(program, name), v1, v2, v3, v4);
}

void SetUniform1d(unsigned int program, const char* name, int value)
{
    glUseProgram(program);
    glUniform1d(glGetUniformLocation(program, name), value);
}

void SetUniform1f(unsigned int program, const char* name, float value)
{
    glUseProgram(program);
    glUniform1f(glGetUniformLocation(program, name), value);
}

void SetUniform1i(unsigned int program, const char* name, int value) 
{
    glUseProgram(program);
    glUniform1i(glGetUniformLocation(program, name), value);
}

void SetUniformMat4(unsigned int program, const char* name, float value[4][4])
{
    glUseProgram(program);
    glUniformMatrix4fv(glGetUniformLocation(program, name), 1, GL_FALSE, &value[0][0]);
}

void SetUniformM4(unsigned int program, const char* name, m4 value)
{
    glUseProgram(program);
    glUniformMatrix4fv(glGetUniformLocation(program, name), 1, GL_FALSE, &value.matrix[0][0]);
}

void UpdateProjection(unsigned int program, const char* name, m4 mvp)
{
    SetUniformM4(program, "U_Transform", mvp);
}

void EasierUpdateProjection(unsigned int program, const char* name, m4* mvp, m4 transform, m4 scale, m4 rotation)
{
    extern vec2 display;
    unsigned int x = display[0], y = display[1];
    mvp->matrix[0][3]  /= x;
    mvp->matrix[1][3] /= y;

    LC_SetMatrix(mvp, LC_Mul(transform, scale).matrix);
    LC_SetMatrix(mvp, LC_Mul(*mvp, rotation).matrix);
    UpdateProjection(program, "U_Transform", *mvp);
}
