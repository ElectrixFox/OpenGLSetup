#include "Shapes.h"

void Square(float cR, int trans)
{
    printf("\nSquare %d", as);

    float vertices[] = 
    {
        0.5f,  0.5f, 0.0f, 1.0f, 1.0f,
        0.5f, -0.5f, 0.0f, 1.0f, 0.0f,
       -0.5f, -0.5f, 0.0f, 0.0f, 0.0f,
       -0.5f,  0.5f, 0.0f, 0.0f, 1.0f
    };

    unsigned int indecies[] = 
    {
        0, 1, 3,
        1, 2, 3
    };

    bs.shaders[as] = CreateShader("texShader.shader");
    SetUniform4f(bs.shaders[as], "U_Colour", cR, 1.0f, 0.0f, 1.0f);
    SetUniform4f(bs.shaders[as], "U_Trans", trans, 0.0f, 0.0f, 1.0f);
    SetUniform1i(bs.shaders[as], "U_Texture", 0);
    SetUniform1f(bs.shaders[as], "U_Tex", 0);
    
    bs.vaos[as] = CreateVertexArray();
    bs.vbos[as] = CreateVertexBuffer(vertices, sizeof vertices);
    AddAttribute(1, 2, 5, 3);
    bs.ibos[as] = CreateIndexBuffer(indecies, sizeof indecies);
    
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, bs.ibos[as]);
    as++;
}

void Triangle(float cR, int trans)
{
    printf("\nTriangle %d", as);

    float vertices[] = 
    {
       -0.5f, -0.5f, 0.0f, 1.0f, 1.0f,
        0.5f, -0.5f, 0.0f, 1.0f, 0.0f,
        0.0f,  0.0f, 0.0f, 0.0f, 0.0f,
    };

    unsigned int indecies[] = 
    {
        0, 1, 2,
    };

    bs.shaders[as] = CreateShader("texShader.shader");
    SetUniform4f(bs.shaders[as], "U_Colour", cR, 1.0f, 0.0f, 1.0f);
    SetUniform4f(bs.shaders[as], "U_Trans", trans, 0.0f, 0.0f, 1.0f);
    SetUniform1i(bs.shaders[as], "U_Texture", 0);
    SetUniform1f(bs.shaders[as], "U_Tex", 0);
    
    bs.vaos[as] = CreateVertexArray();
    bs.vbos[as] = CreateVertexBuffer(vertices, sizeof vertices);
    AddAttribute(1, 2, 5, 3);
    bs.ibos[as] = CreateIndexBuffer(indecies, sizeof indecies);
    
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, bs.ibos[as]);
    as++;
}

void Image(const char* FilePath, int trans)
{
    printf("\nImage %d", as);

    bs.shaders[as] = CreateShader("texShader.shader");

    float vertices[] = 
    {
        0.5f,  0.5f, 0.0f, 1.0f, 1.0f,
        0.5f, -0.5f, 0.0f, 1.0f, 0.0f,
       -0.5f, -0.5f, 0.0f, 0.0f, 0.0f,
       -0.5f,  0.5f, 0.0f, 0.0f, 1.0f
    };

    unsigned int indecies[] = 
    {
        0, 1, 3,
        1, 2, 3
    };

    bs.vaos[as] = CreateVertexArray();
    bs.vbos[as] = CreateVertexBufferDepth(vertices, sizeof vertices, 0, 3, 5, 0);
    AddAttribute(1, 2, 5, 3);

    bs.textures[as] = CreateTexture(FilePath);
    bs.ibos[as] = CreateIndexBuffer(indecies, sizeof indecies);

    SetUniform4f(bs.shaders[as], "U_Colour", 1.0f, 0.5f, 0.2f, 1.0f);
    SetUniform4f(bs.shaders[as], "U_Trans", trans, 0.0f, 0.0f, 1.0f);
    SetUniform1i(bs.shaders[as], "U_Texture", 0);
    SetUniform1f(bs.shaders[as], "U_Tex", 1);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, bs.ibos[as]);
    as++;
}

