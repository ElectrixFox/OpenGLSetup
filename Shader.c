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

ShaderSources PharseShader(const LCstring FilePath)
{
    int size = sizeof(char*) * 1024;
    char* source = malloc(size);


    FILE* fp;
    fp = fopen(FilePath, "r");

    fscanf(fp, "s", &source);

    char* line = NULL;

    char* OS[2];
    OS[0] = malloc(sizeof(char*) * 1024);
    OS[1] = malloc(sizeof(char*) * 1024);

    memset(OS[0], 0, 1024);
    memset(OS[1], 0, 1024);

    size_t line_buffsize = 0;
    while(getline(&line, &line_buffsize, fp) != -1)
    {
        static int i = 0;

        if(Find("#shader", line) != -1)
        {
            if(Find("#shader Vertex", line) != -1)
            {
                i = 0;
            }
            else if(Find("#shader Fragment", line) != -1)
            {
                i = 1;
            }
            else
            {

            }
        }
        else
        {
            Append(line, &OS[i]);
        }


    }
    fclose(fp);

    ShaderSources ss;

    ss.VertexSource = OS[0];
    ss.FragmentSource = OS[1];
    
    return ss;
}

unsigned int CreateShader(const LCstring FilePath)
{
    ShaderSources ss = PharseShader(FilePath);

    const char* VSS = ss.VertexSource;
    const char* FSS = ss.FragmentSource;

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
            printf("Vertex shader broken: %s", vS);
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
            printf("Fragment shader broken: %s", fS);
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
            printf("Program broken broken: %s", program);
        }
    };

    glUseProgram(program);
    glDeleteShader(vS);
    glDeleteShader(fS);

    return program;
};

void SetUniform4f(unsigned int program, LCstring name, float v1, float v2, float v3, float v4) 
{
    glUseProgram(program);
    glUniform4f(glGetUniformLocation(program, name), v1, v2, v3, v4);
}

void SetUniform1i(unsigned int program, LCstring name, int value) 
{
    glUseProgram(program);
    glUniform1i(glGetUniformLocation(program, name), value);
}

void SetUniformMat4(unsigned int program, LCstring name, float value[4][4])
{
    glUseProgram(program);
    glUniformMatrix4fv(glGetUniformLocation(program, name), 1, GL_FALSE, &value[0][0]);
}

void SetUniformM4(unsigned int program, LCstring name, m4 value)
{
    glUseProgram(program);
    glUniformMatrix4fv(glGetUniformLocation(program, name), 1, GL_FALSE, &value.matrix[0][0]);
}

void TransformInWindow(m4* projection, vec3 transform)
{
    int w, h;
    w = Width_x;
    h = Height_y;

    transform[0] /= w;
    transform[1] /= h;
    
    m4 m = *projection;
    m = Transform_OPENGL(m, transform);

    projection = &m;
}

void ScaleInWindow(m4* projection, vec3 Scale)
{
    m4 m = *projection;
    m = Scale_OPENGL(m, Scale);

    projection = &m;
}

void UpdateProjection(unsigned int program, m4 pos, m4 scale)
{
    m4 projection = M4_Identity();
    projection = Mul(scale, pos);

    SetUniformM4(program, "U_Transform", projection);
}