#include "RenderComponent.h"

static int x = 1;

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
    SetUniformM4(shader, "U_Transform", LC_M4_Identity());
    SetUniform4f(shader, "U_Colour", 1.0 / x++, 0.0, 0.0, 1.0);

    unsigned int vao = CreateVertexArray();
    unsigned int vbo = CreateVertexBuffer(vertex, 20);
    unsigned int ibo = CreateIndexBuffer(index, 6);
    
    add<RenderComponent>(world, entity, Types::T_Render, { vao, ibo, shader, 0, vbo });
}

RenderComponent CreateNewSquare(World* world, Entity entity, int flags)
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
    SetUniformM4(shader, "U_Transform", LC_M4_Identity());
    SetUniform4f(shader, "U_Colour", 1.0 / x++, 0.0, 0.0, 1.0);

    unsigned int vao = CreateVertexArray();
    unsigned int vbo = CreateVertexBuffer(vertex, 20);
    unsigned int ibo = CreateIndexBuffer(index, 6);
    
    if(flags) add<RenderComponent>(world, entity, Types::T_Render, { vao, ibo, shader, 0, vbo });

    RenderComponent re = { vao, ibo, shader, 0, vbo };
    return re;
}

void CreateNewSquare(World* world, Entity entity, std::string Texture_FilePath)
{
    // The vertex for the square
    float vertex[] =
    {
        0.5f,  0.5f, 0.0f, 1.0f, 1.0f,
        0.5f, -0.5f, 0.0f, 1.0f, 0.0f,
       -0.5f, -0.5f, 0.0f, 0.0f, 0.0f,
       -0.5f,  0.5f, 0.0f, 0.0f, 1.0f
    };

    // Index for the index buffer
    unsigned int index[] =
    {
        0, 1, 3,
        1, 2, 3
    };

    // To-Do: Make the shader source in this function to increase speed by not having to open and read from a file
    // Creating a texture shader that is used to show the texture
    unsigned int shader = CreateShader("res/texShader.shader");
    unsigned int texture = CreateTexture(Texture_FilePath.c_str());

    // To-Do: Make it a macro to make it easier to automatically set
    // Setting the default uniforms
    SetUniformM4(shader, "U_Transform", LC_M4_Identity());
    SetUniform4f(shader, "U_Colour", 1.0, 0.0, 0.0, 1.0);

    SetUniform1i(shader, "U_Texture", 0);

    unsigned int vao = CreateVertexArray();
    unsigned int vbo = CreateVertexBufferDepth(vertex, sizeof(vertex), 0, 3, 5, 0);
    unsigned int ibo = CreateIndexBuffer(index, 6);
    AddAttribute(1, 2, 5, 3);

    // Adding the new component
    add<RenderComponent>(world, entity, Types::T_Render, { vao, ibo, shader, texture, vbo });
}

void Draw(RenderComponent* res, m4* projs, std::vector<Entity> entities, int vertex_size, int indecies_size)
{
    int n = entities.size();

    for (int i = 0; i < n; i++)
    {
        unsigned int ID = entities[i].ID;
        
        // They're in this order so that they can be loaded contigously which should have a very small effect on speed
        // It's just an incredibly small optimisation that the compiler probably does
        unsigned int v[4] = { res[ID].texture, res[ID].shader, res[ID].vao, res[ID].ibo };

        glBindTexture(GL_TEXTURE_2D, v[0]);

        glUseProgram(v[1]);
        SetUniformM4(v[1], "U_Transform", projs[i]);

        glBindVertexArray(v[2]);

        if(v[3] != 0)
        {
            glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, v[3]);
            glDrawElements(GL_TRIANGLES, indecies_size, GL_UNSIGNED_INT, 0);
        }

        glDrawArrays(GL_TRIANGLES, 0, vertex_size);
    }

// ===============================NEW=============================== //
    free(res);
}

void Draw(RenderComponent* res, std::vector<m4> projs, std::vector<Entity> entities)
{
    int n = entities.size();

    for (int i = 0; i < n; i++)
    {
        unsigned int ID = entities[i].ID;
        
        unsigned int v[4] = { res[ID].texture, res[ID].shader, res[ID].vao, res[ID].ibo };

        // To-Do: Separate this out to make it more parrallisable
        extern m4 VP;
        m4 MVP = LC_Mul(projs.at(i), VP);

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

// ===============================NEW=============================== //
    free(res);
}