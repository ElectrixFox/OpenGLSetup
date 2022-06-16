#include "src/RenderComponent.h"

void InitComponents(Render_Components& rendercomponents)
{
    rendercomponents.vaos = (unsigned int*)malloc(sizeof(unsigned int) * 1000);
    rendercomponents.ibos = (unsigned int*)malloc(sizeof(unsigned int) * 1000);
    rendercomponents.shaders = (unsigned int*)malloc(sizeof(unsigned int) * 1000);
    rendercomponents.textures = (unsigned int*)malloc(sizeof(unsigned int) * 1000);
}

unsigned int Hash(Render_Components rendercomponents)
{
    unsigned int ID = rand() % 1000;

    if(rendercomponents.vaos[ID] != 0)
    {
        Hash(rendercomponents);
    }

    return ID;
}

Render_Component getAsset(Render_Components rendercomponents, Render_Entity renderentity)
{
    Render_Component re = { rendercomponents.vaos[renderentity.ID], rendercomponents.ibos[renderentity.ID], rendercomponents.shaders[renderentity.ID], rendercomponents.textures[renderentity.ID]};

    return re;
}


void addRenderComponent(Render_Components& rendercomponents, Render_Entity& renderentity)
{
    unsigned int ID = Hash(rendercomponents);
    renderentity.ID = ID;

    rendercomponents.vaos[ID] = PRESENT;
    rendercomponents.ibos[ID] = PRESENT;
    rendercomponents.shaders[ID] = PRESENT;
    rendercomponents.textures[ID] = PRESENT;
}

void addAsset(unsigned int vao, unsigned int ibo, unsigned int shader, unsigned int texture)
{

}

void Draw(Render_Components rendercomponents, Render_Entity renderentity, m4 proj)
{
    Render_Component re = getAsset(rendercomponents, renderentity);

    glBindTexture(GL_TEXTURE_2D, re.texture);

    extern m4 View, Projection, VP;

    m4 MVP = Mul(proj, VP);

    glUseProgram(re.shader);
    SetUniformM4(re.shader, "U_Transform", MVP);

    glBindVertexArray(re.vao);

    if(re.ibo != 0)
    {
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, re.ibo);
        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
    }

    glDrawArrays(GL_TRIANGLES, 0, 6);
}

void Draw(Render_Components rendercomponents)
{

}

void CreateNewSquare(Render_Component& rendercomponent)
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

    unsigned int texture;

    rendercomponent.ibo = ibo;
    rendercomponent.vao = vao;
    rendercomponent.shader = shader;
    rendercomponent.texture = 0;

}