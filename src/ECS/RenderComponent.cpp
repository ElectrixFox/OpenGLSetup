#include "RenderComponent.h"

void CreateNewSquare(World* world, Entity entity)
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
    
    add<RenderComponent>(world, entity, Types::T_Render, { vao, ibo, shader, texture });
}

void CreateNewSquare(World* world, Entity entity, std::string Texture_FilePath)
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

    add<RenderComponent>(world, entity, Types::T_Render, { vao, ibo, shader, texture });
}

void Draw(RenderComponent* res, std::vector<m4> projs, std::vector<Entity> entities)
{
    int n = entities.size();

    for (int i = 0; i < n; i++)
    {
        unsigned int ID = entities[i].ID;
        
        unsigned int v[4] = { res[ID].texture, res[ID].shader, res[ID].vao, res[ID].ibo };

        // To-Do: Separate this out to make it more parrallisable
        extern m4 View, Projection, VP;
        m4 MVP = Mul(projs.at(i), VP);

        glBindTexture(GL_TEXTURE_2D, v[0]);

        glUseProgram(v[1]);
        SetUniformM4(v[1], "U_Transform", MVP);

        glBindVertexArray(v[2]);

        if(v[3] != 0)
        {
            glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, v[3]);
            glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
        }

        glDrawArrays(GL_TRIANGLES, 0, 6);
    }
}