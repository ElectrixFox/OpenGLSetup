#define STB_IMAGE_IMPLEMENTATION
#include <STB/stb_image.h>

#include <stdio.h>
#include <stdlib.h>
#include <GLEW/glew.h>
#include <GLFW/glfw3.h>

const char *vertexShaderSource = "#version 430 core\n"
    "layout (location = 0) in vec3 aPos;\n"
    "void main()\n"
    "{\n"
    "   gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
    "}\0";

const char *fragmentShaderSource = "#version 430 core\n"
    "out vec4 FragColour;\n"
    "void main()\n"
    "{\n"
    "   FragColour = vec4(1.0f, 0.5f, 0.2f, 1.0f);\n"
    "}\n\0";

int main()
{
    printf("Hello World!");

    glfwInit();

    GLFWwindow* window = glfwCreateWindow(400, 400, "Test Window", NULL, NULL);
    glfwMakeContextCurrent(window);

    glewInit();

    float vertex[] =
    {
        -0.5f, -0.5f, 0.0f, 0.0f, 0.0f,
         0.5f, -0.5f, 0.0f, 1.0f, 0.0f,
         0.0f,  0.5f, 0.0f, 0.5f, 1.0f
    };

    float texCoords[] =
    {
        0.0f, 0.0f,
        1.0f, 0.0f,
        0.5f, 1.0f
    };

    int success;
    char infolog[512];

    unsigned int v_shader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(v_shader, 1, &vertexShaderSource, NULL);
    glCompileShader(v_shader);
    
    glGetShaderiv(v_shader, GL_COMPILE_STATUS, &success);
    
    if(!success)
    {
        printf("\nVertex shader is broke");

        glGetShaderInfoLog(v_shader, 512, NULL, infolog);
        printf("\nLets have a looksie what's wrong with it: %s", infolog);
    }

    unsigned int f_shader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(f_shader, 1, &fragmentShaderSource, NULL);
    glCompileShader(f_shader);

    glGetShaderiv(f_shader, GL_COMPILE_STATUS, &success);
    
    if(!success)
    {
        printf("\nFragment shader is broke");

        glGetShaderInfoLog(f_shader, 512, NULL, infolog);
        printf("\nLets have a looksie what's wrong with it: %s", infolog);
    }

    unsigned int program = glCreateProgram();
    glAttachShader(program, v_shader);
    glAttachShader(program, f_shader);
    glLinkProgram(program);

    glGetProgramiv(program, GL_LINK_STATUS, &success);
    if(!success)
    {
        printf("\nThe program doesn't want to do the linkie winkie");

        glGetProgramInfoLog(program, 512, NULL, infolog);
        printf("\nLet's have a sneeky peaky at why it no work: %s", infolog);
    }

    glDeleteShader(v_shader);
    glDeleteShader(f_shader);

    unsigned int vao, vbo;
    glGenVertexArrays(1, &vao);
    glGenBuffers(1, &vbo);

    glBindVertexArray(vao);

    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertex), vertex, GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(6 * sizeof(float)));
    glEnableVertexAttribArray(2);

    glBindBuffer(GL_ARRAY_BUFFER, 0);

    glBindVertexArray(0);

    // Texture stuff
    int width, height, channels;
    unsigned char* data = stbi_load("Face.png", &width, &height, &channels, 0);

    unsigned int texture;
    glGenTextures(1, &texture);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
    glGenerateMipmap(GL_TEXTURE_2D);

    stbi_image_free(data);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_MIRRORED_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_MIRRORED_REPEAT);

    while(!glfwWindowShouldClose(window))
    {
        glClear(GL_COLOR_BUFFER_BIT);
        
        glUseProgram(program);
        glBindVertexArray(vao);
        glDrawArrays(GL_TRIANGLES, 0, 3);

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glDeleteVertexArrays(1, &vao);
    glDeleteProgram(program);
    glDeleteBuffers(1, &vbo);

    glfwTerminate();
    return 0;
}