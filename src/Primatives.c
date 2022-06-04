#include "Primatives.h"

Queue items;

struct Render_Data
{
    unsigned int* vaos;
    unsigned int* ibos;
    unsigned int* shaders;
    unsigned short int* textures;
};

static struct Render_Data render_data;

void AddItem(unsigned int vao, unsigned int ibo, unsigned int shader, unsigned short int texture)
{
    items.size++;

    render_data.vaos[items.Tail] = vao;
    render_data.ibos[items.Tail] = ibo;
    render_data.shaders[items.Tail] = shader;
    render_data.textures[items.Tail] = texture;

    items.Tail = (items.Tail + 1) % items.size;
};

unsigned int* GetItem()
{
    unsigned int* renderdata;

    if(isEmpty(items)) return 0;

    renderdata[0] = render_data.vaos[items.Head];
    renderdata[1] = render_data.ibos[items.Head];
    renderdata[2] = render_data.shaders[items.Head];
    renderdata[3] = render_data.textures[items.Head];

    items.Head = (items.Head + 1) % items.size;

    return renderdata;
}
