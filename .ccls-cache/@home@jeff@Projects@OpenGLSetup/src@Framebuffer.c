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
    extern vec2 display;

    unsigned int texture;
	glGenTextures(1, &texture);
	glBindTexture(GL_TEXTURE_2D, texture);

	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, display[0], display[1], 0, GL_RGB, GL_UNSIGNED_BYTE, NULL);

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

    extern vec2 display;
	glRenderbufferStorage(GL_RENDERBUFFER, GL_DEPTH24_STENCIL8, display[0], display[1]);
	glFramebufferRenderbuffer(GL_FRAMEBUFFER, GL_DEPTH_STENCIL_ATTACHMENT, GL_RENDERBUFFER, rbo);

	return rbo;
}

void SetupFramBuffer()
{
    const char* shaderSources =
    {
        "#shader Vertex\n"
        "#version 330 core\n"
        "layout (location = 0) in vec2 aPos;\n"
        "layout (location = 1) in vec2 aTexCoords;\n"
        "\n"
        "out vec2 TexCoords;\n"
        "\n"
        "void main()\n"
        "{\n"
        "    gl_Position = vec4(aPos.x, aPos.y, 0.0, 1.0); \n"
        "    TexCoords = aTexCoords;\n"
        "}\n"
        "\n"
        "#shader Fragment\n"
        "#version 330 core\n"
        "out vec4 FragColour;\n"
        "  \n"
        "in vec2 TexCoords;\n"
        "\n"
        "uniform sampler2D screenTexture;\n"
        "\n"
        "void main()\n"
        "{ \n"
        "    FragColour = texture(screenTexture, TexCoords);\n"
        "}"
    };

    float vertices[] =
    {
        -1.0f,  1.0f,  0.0f, 1.0f,
        -1.0f, -1.0f,  0.0f, 0.0f,
         1.0f, -1.0f,  1.0f, 0.0f,

        -1.0f,  1.0f,  0.0f, 1.0f,
         1.0f, -1.0f,  1.0f, 0.0f,
         1.0f,  1.0f,  1.0f, 1.0f
    };

    unsigned int FboShader = CreateShaderFromChar(shaderSources);
    unsigned int Quadvao = CreateVertexArray();
    unsigned int Quadvbo = CreateVertexBufferDepth(vertices, sizeof vertices, 0, 2, 4, 0);
    AddAttribute(1, 2, 4, 2);
    glUseProgram(FboShader);
    SetUniform1i(FboShader, "screenTexture", 0);
    
    unsigned char fbo = CreateFramebuffer();
    unsigned int screen_texture = TextureAttachment();
    unsigned char rbo = Renderbuffer();
    glBindFramebuffer(GL_FRAMEBUFFER, 0);

}
