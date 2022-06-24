#include "RenderComponent.h"
#include "ecs.h"


void CreateNewSquare(World& world, Entity entity)
{
    float vertex[] =
    {
        0.5f,  0.5f, 0.0f, 1.0f, 1.0f,
        0.5f, -0.5f, 0.0f, 1.0f, 0.0f,
       -0.5f, -0.5f, 0.0f, 0.0f, 0.0f,
       -0.5f,  0.5f, 0.0f, 0.0f, 1.0f
    };

    unsigned int index[] =
    {
        0, 1, 3,
        1, 2, 3
    };


    unsigned int shader = CreateShader("res/shader.shader");
    SetUniformM4(shader, "U_Transform", M4_Identity());
    SetUniform4f(shader, "U_Colour", 1.0, 0.0, 0.0, 1.0);

    unsigned int vao = CreateVertexArray();
    unsigned int vbo = CreateVertexBuffer(vertex, 20);
    unsigned int ibo = CreateIndexBuffer(index, 6);

    unsigned int texture = 0;

    world.renderComponents.ibos[entity.EntityID] = ibo;
    world.renderComponents.vaos[entity.EntityID] = vao;
    world.renderComponents.shaders[entity.EntityID] = shader;
    world.renderComponents.textures[entity.EntityID] = texture;
}

void CreateNewSquare(World& world, Entity entity, std::string Texture_FilePath)
{
    float vertex[] =
    {
        0.5f,  0.5f, 0.0f, 1.0f, 1.0f,
        0.5f, -0.5f, 0.0f, 1.0f, 0.0f,
       -0.5f, -0.5f, 0.0f, 0.0f, 0.0f,
       -0.5f,  0.5f, 0.0f, 0.0f, 1.0f
    };

    unsigned int index[] =
    {
        0, 1, 3,
        1, 2, 3
    };

    unsigned int shader = CreateShader("res/texShader.shader");
    unsigned int texture = CreateTexture(Texture_FilePath.c_str());
    SetUniformM4(shader, "U_Transform", M4_Identity());
    SetUniform4f(shader, "U_Colour", 1.0, 0.0, 0.0, 1.0);

    SetUniform1i(shader, "U_Texture", 0);

    unsigned int vao = CreateVertexArray();
    unsigned int vbo = CreateVertexBufferDepth(vertex, sizeof(vertex), 0, 3, 5, 0);
    unsigned int ibo = CreateIndexBuffer(index, 6);
    AddAttribute(1, 2, 5, 3);


    world.renderComponents.ibos[entity.EntityID] = ibo;
    world.renderComponents.vaos[entity.EntityID] = vao;
    world.renderComponents.shaders[entity.EntityID] = shader;
    world.renderComponents.textures[entity.EntityID] = texture;
}

void Draw(RenderComponents res, std::vector<m4> projs, int n)
{
    for (int i = 0; i < n; i++)
    {
        unsigned int vao = res.vaos[i];
        unsigned int ibo = res.ibos[i];
        unsigned int shader =  res.shaders[i];
        unsigned int texture =  res.textures[i];

        extern m4 View, Projection, VP;

        m4 MVP = Mul(projs.data()[i], VP);
        
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
}