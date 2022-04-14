#include "Shapes.h"

MeshObject Square(float cR, vec3 trans, vec3 scale)
{
    MeshObject mesh = {0};
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

    unsigned int program, vbo, vao, ibo;
    program = CreateShader("shader.shader");

    SetUniformM4(program, "U_Transform", M4_Identity());

    SetUniform4f(program, "U_Colour", cR, 1.0f, 0.0f, 1.0f);

    vao = CreateVertexArray();
    vbo = CreateVertexBuffer(vertices, sizeof vertices);
    ibo = CreateIndexBuffer(indecies, sizeof indecies);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ibo);

    Buffer buffer = {vbo, vao, ibo, program, 0};
    TransformObject to = {.position = {trans[0], trans[1]}, {0}, {scale[0], scale[1], scale[3]}};

    printf("ibo = %d, vbo = %d, vao = %d, program = %d\n", ibo, vbo, vao, program);

    mesh.buffer = buffer;
    mesh.transformObject = to;

    return mesh;
}

MeshObject Triangle(float cR, vec3 trans, vec3 scale)
{
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

    unsigned int program, vbo, vao, ibo;
    program = CreateShader("shader.shader");

    SetUniformM4(program, "U_Transform", M4_Identity());

    SetUniform4f(program, "U_Colour", cR, 1.0f, 0.0f, 1.0f);

    vao = CreateVertexArray();
    vbo = CreateVertexBuffer(vertices, sizeof vertices);
    ibo = CreateIndexBuffer(indecies, sizeof indecies);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ibo);
    printf("ibo = %d, vbo = %d, vao = %d, program = %d\n", ibo, vbo, vao, program);

    Buffer buffer = (Buffer){vbo, vao, ibo, program, 0};
    TransformObject transformObject = {{trans[0], trans[1]}, {0}, {scale[0], scale[1], scale[2]}};
    MeshObject mesh = {0};

    mesh.buffer = buffer;
    mesh.transformObject = transformObject;

    return mesh;
}

MeshObject Image(const char* FilePath, vec3 trans, vec3 scale)
{
    unsigned int program, vbo, vao, ibo;
    program = CreateShader("texShader.shader");

    unsigned int texture;
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

    vao = CreateVertexArray();
    vbo = CreateVertexBufferDepth(vertices, sizeof vertices, 0, 3, 5, 0);
    AddAttribute(1, 2, 5, 3);

    texture = CreateTexture(FilePath);
    ibo = CreateIndexBuffer(indecies, sizeof indecies);

    SetUniform4f(program, "U_Colour", 1.0f, 0.5f, 0.2f, 1.0f);

    SetUniform1i(program, "U_Texture", 0);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ibo);

    printf("ibo = %d, vbo = %d, vao = %d, program = %d, texture = %d\n", ibo, vbo, vao, program, texture);

    Buffer buffer = (Buffer){vbo, vao, ibo, program, texture};
    TransformObject transformObject = {{trans[0], trans[1]}, {0}, {scale[0], scale[1], scale[2]}};
    MeshObject mesh = {0};

    mesh.buffer = buffer;
    mesh.transformObject = transformObject;

    return mesh;
}

void SetArray(vec3* array, vec3 item, int index)
{
    for(int i = 0; i < 3; i++)
        array[index][i] = item[i];
}

