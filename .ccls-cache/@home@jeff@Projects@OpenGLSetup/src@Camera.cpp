#include "Camera.h"

vec3 pos;

m4 Projection;
m4 View;
m4 VP;

void Camera(m4* cam, vec3 position)
{
	ViewMatrix(cam, position);
}

void UpdateCamera()
{
    VP = Mul(View, Projection);

    vec3 funnel = {pos[0], pos[1], pos[2]};
    Camera(&View, funnel);
}

void TransformCamera(vec3 position)
{
    pos[0] = position[0];
    pos[1] = position[1];
    pos[2] = position[2];
}

void TranslateCamera(vec3 translation)
{
    pos[0] += translation[0];
    pos[1] += translation[1];
    pos[2] += translation[2];
}

void initMatricies()
{
    View = M4_Identity();
    Projection = M4_Identity();
}

FrameBufferObject initFrameBuffer()
{
    FrameBufferObject fbO;

    float vertices[] =
    {
        -1.0f,  1.0f,  0.0f, 1.0f,
        -1.0f, -1.0f,  0.0f, 0.0f,
         1.0f, -1.0f,  1.0f, 0.0f,

        -1.0f,  1.0f,  0.0f, 1.0f,
         1.0f, -1.0f,  1.0f, 0.0f,
         1.0f,  1.0f,  1.0f, 1.0f
    };

    unsigned int FboShader = CreateShader("res/FrameBuffer.shader");
    unsigned int Quadvao = CreateVertexArray();
    unsigned int Quadvbo = CreateVertexBufferDepth(vertices, sizeof vertices, 0, 2, 4, 0);
    AddAttribute(1, 2, 4, 2);
    glUseProgram(FboShader);
    SetUniform1i(FboShader, "screenTexture", 0);

    unsigned char fbo = CreateFramebuffer();
    unsigned int screen_texture = TextureAttachment();
    unsigned char rbo = Renderbuffer();

    fbO.fbo = fbo;
    fbO.screen_texture = screen_texture;
    fbO.vao = Quadvao;
    fbO.shader = FboShader;

    return fbO;
};

void DrawFBO(unsigned char vao, unsigned char shader, unsigned char screen_texture)
{
    m4 model = M4_Identity();

    extern m4 VP;
    m4 MVP = Mul(model, VP);

    glBindTexture(GL_TEXTURE_2D, screen_texture);

    glUseProgram(shader);
    SetUniformM4(shader, "U_Transform", MVP);

    glBindVertexArray(vao);

    glDrawArrays(GL_TRIANGLES, 0, 6);
}
