#include "Framebuffer.h"

unsigned int CreateFramebuffer()
{
	unsigned int fbo;
	glGenFramebuffers(1, &fbo);
	glBindFramebuffer(GL_FRAMEBUFFER, fbo);

	return fbo;
}

unsigned int TextureAttachment()
{
	unsigned int texture;
	glGenTextures(1, &texture);
	glBindTexture(GL_TEXTURE_2D, texture);

	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, 960, 540, 0, GL_RGB, GL_UNSIGNED_BYTE, NULL);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_TEXTURE_2D, texture, 0);

	return texture;
}

unsigned int Renderbuffer()
{
	unsigned int rbo;
	glGenRenderbuffers(1, &rbo);
	glBindRenderbuffer(GL_RENDERBUFFER, rbo);

	glRenderbufferStorage(GL_RENDERBUFFER, GL_DEPTH24_STENCIL8, 960, 540);
	glFramebufferRenderbuffer(GL_FRAMEBUFFER, GL_DEPTH_STENCIL_ATTACHMENT, GL_RENDERBUFFER, rbo);
//	glBindRenderbuffer(GL_RENDERBUFFER, 0);
	return rbo;
}

RenderManager InitialiseFrameBuffer()
{

    float vertices[] =
    {
        -1.0f,  1.0f,  0.0f, 1.0f,
        -1.0f, -1.0f,  0.0f, 0.0f,
         1.0f, -1.0f,  1.0f, 0.0f,

        -1.0f,  1.0f,  0.0f, 1.0f,
         1.0f, -1.0f,  1.0f, 0.0f,
         1.0f,  1.0f,  1.0f, 1.0f
    };

    unsigned int FboShader = CreateShader("FrameBuffer.shader");
    unsigned int Quadvao = CreateVertexArray();
    unsigned int Quadvbo = CreateVertexBufferDepth(vertices, sizeof vertices, 0, 2, 4, 0);
    AddAttribute(1, 2, 4, 2);
    glUseProgram(FboShader);
    SetUniform1i(FboShader, "screenTexture", 0);

    
    unsigned char fbo = CreateFramebuffer();
    unsigned int screen_texture = TextureAttachment();
    unsigned char rbo = Renderbuffer();
    glBindFramebuffer(GL_FRAMEBUFFER, 0);

    RenderManager rm;
    rm.FrameBuffer = fbo;
    rm.fbo.shader = FboShader;
    rm.fbo.vao = Quadvao;
    rm.fbo.texture = screen_texture;

    return rm;
}
