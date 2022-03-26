#include "Shapes.h"

void Square(float cR, vec3 trans, vec3 scale)
{
    /* *Shapes_Data.Transforms[as] = *trans;
    *Shapes_Data.Scales[as] = *scale;
    *Shapes_Data.Rotations[as] = *(vec3){0, 0, 0}; */

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

    SetUniformM4(bs.shaders[as], "U_Transform", M4_Identity());

    SetUniform4f(bs.shaders[as], "U_Colour", cR, 1.0f, 0.0f, 1.0f);

    m4 MVP = M4_Identity();
    m4 Model = M4_Identity();
    m4 View = M4_Identity();
    
    View = Mul(Rotation(View, 90, (vec3){1.0f, 0.0f, 0.0f}), LookAt((vec3){1, 0, 0}, (vec3){0, 1, 0}, (vec3){0, 0, 1}, (vec3){0, 0, 0}));

    Transform(&Model, trans);
    Scale(&Model, scale);

    MVP = Mul(Mul(Model, View), Projection);
    SetUniformM4(bs.shaders[as], "U_Transform", MVP);

    SetUniform1i(bs.shaders[as], "U_Texture", 0);
    SetUniform1f(bs.shaders[as], "U_Tex", 0);
    
    bs.vaos[as] = CreateVertexArray();
    bs.vbos[as] = CreateVertexBuffer(vertices, sizeof vertices);
    AddAttribute(1, 2, 5, 3);
    bs.ibos[as] = CreateIndexBuffer(indecies, sizeof indecies);
    
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, bs.ibos[as]);
    as++;
}

void Triangle(float cR, vec3 trans, vec3 scale)
{
    /* *Shapes_Data.Transforms[as] = *trans;
    *Shapes_Data.Scales[as] = *scale;
    *Shapes_Data.Rotations[as] = *(vec3){0, 0, 0}; */

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
    
    SetUniformM4(bs.shaders[as], "U_Transform", M4_Identity());

    SetUniform4f(bs.shaders[as], "U_Colour", cR, 1.0f, 0.0f, 1.0f);

    m4 proj = M4_Identity();
    Transform(&proj, trans);
    Scale(&proj, scale);
    SetUniformM4(bs.shaders[as], "U_Transform", proj);

    SetUniform1i(bs.shaders[as], "U_Texture", 0);
    SetUniform1f(bs.shaders[as], "U_Tex", 0);
    
    bs.vaos[as] = CreateVertexArray();
    bs.vbos[as] = CreateVertexBuffer(vertices, sizeof vertices);
    AddAttribute(1, 2, 5, 3);
    bs.ibos[as] = CreateIndexBuffer(indecies, sizeof indecies);
    
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, bs.ibos[as]);
    as++;
}

void Image(const char* FilePath, vec3 trans, vec3 scale)
{
    SetArray(&Shapes_Data.Transforms, trans, as);
    SetArray(&Shapes_Data.Scales, scale, as);
    SetArray(&Shapes_Data.Rotations, (vec3){0, 0, 0}, as);

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

    m4 proj = M4_Identity();
    Transform(&proj, trans);
    Scale(&proj, scale);
    SetUniformM4(bs.shaders[as], "U_Transform", proj);

    SetUniform1i(bs.shaders[as], "U_Texture", 0);
    SetUniform1f(bs.shaders[as], "U_Tex", 1);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, bs.ibos[as]);
    as++;
}

void SetArray(vec3* array, vec3 item, int index)
{
    for(int i = 0; i < 3; i++)
        array[index][i] = item[i];
}

