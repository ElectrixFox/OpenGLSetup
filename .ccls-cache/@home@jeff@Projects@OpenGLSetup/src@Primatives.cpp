#include "Primatives.h"

Queue items;

using namespace std;

struct Render_Data
{
    unsigned int* vaos;
    unsigned int* ibos;
    unsigned int* shaders;
    unsigned short int* textures;
};

static struct Render_Data render_data;

void initItems()
{
    render_data.vaos = (unsigned int*)malloc(sizeof(unsigned int) * 256);
    render_data.ibos = (unsigned int*)malloc(sizeof(unsigned int) * 256);
    render_data.shaders = (unsigned int*)malloc(sizeof(unsigned int) * 256);
    render_data.textures = (unsigned short int*)malloc(sizeof(unsigned int) * 256);
}

void AddItem(unsigned int vao, unsigned int ibo, unsigned int shader, unsigned short int texture)
{
    items.size++;

    render_data.vaos[items.Tail] = vao;
    render_data.ibos[items.Tail] = ibo;
    render_data.shaders[items.Tail] = shader;
    render_data.textures[items.Tail] = texture;

    items.Tail = (items.Tail + 1) % items.size;
};

RenderItem GetItem()
{
    RenderItem renderdata;

    if(isEmpty(items)) goto end;

    renderdata.vao = render_data.vaos[items.Head];
    renderdata.ibo = render_data.ibos[items.Head];
    renderdata.shader = render_data.shaders[items.Head];
    renderdata.texture = render_data.textures[items.Head];

    items.Head = (items.Head + 1) % items.size;

end:
    return renderdata;
}

void CreateSquare()
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

    AddItem(vao, ibo, shader);
}

void CreateSquare(string Texture_FilePath)
{

}
