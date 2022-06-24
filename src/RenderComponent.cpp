#include "RenderComponent.h"
#include "ecs.h"


void CreateNewSquare(World& world, RenderComponent& rendercomponent)
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

    static int i = 0;
    i++;

    world.renderComponents.ibos[i] = ibo;
    world.renderComponents.vaos[i] = vao;
    world.renderComponents.shaders[i] = shader;
    world.renderComponents.textures[i] = texture;
}

void CreateNewSquare(RenderComponent& rendercomponent, std::string Texture_FilePath)
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
    unsigned short int texture = CreateTexture("res/Boris.png");
    SetUniformM4(shader, "U_Transform", M4_Identity());
    SetUniform4f(shader, "U_Colour", 1.0, 0.0, 0.0, 1.0);

    SetUniform1i(shader, "U_Texture", 0);

    unsigned int vao = CreateVertexArray();
    unsigned int vbo = CreateVertexBufferDepth(vertex, sizeof(vertex), 0, 3, 5, 0);
    unsigned int ibo = CreateIndexBuffer(index, 6);
    AddAttribute(1, 2, 5, 3);



    rendercomponent.ibo = ibo;
    rendercomponent.vao = vao;
    rendercomponent.shader = shader;
    rendercomponent.texture = texture;

}

/* void Draw(Entity entity, m4 proj)
{
    extern World world;
    RenderComponent re = ecs::get<RenderComponent>(world, entity);

    glBindTexture(GL_TEXTURE_2D, *re.texture);

    extern m4 View, Projection, VP;

    m4 MVP = Mul(proj, VP);

    glUseProgram(*re.shader);
    SetUniformM4(*re.shader, "U_Transform", MVP);

    glBindVertexArray(*re.vao);

    if(*re.ibo != 0)
    {
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, *re.ibo);
        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
    }

    glDrawArrays(GL_TRIANGLES, 0, 6);
} */