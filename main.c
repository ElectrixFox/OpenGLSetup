#define STB_IMAGE_IMPLEMENTATION
#include <STB/stb_image.h>

#include <stdio.h>
#include <stdlib.h>
#include <GLEW/glew.h>
#include <GLFW/glfw3.h>

const char *vertexShaderSource = "#version 430 core\n"
    "layout (location = 0) in vec3 aPos;\n"
    "layout (location = 1) in vec2 Texpos;\n"
    "out vec2 TexCoords;\n"
    "uniform mat4 U_Projection;\n"
    "void main()\n"
    "{\n"
    "   gl_Position = U_Projection * vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
    "   TexCoords = Texpos;\n"
    "}\0";

const char *fragmentShaderSource = "#version 430 core\n"
    "out vec4 FragColour;\n"
    "in vec2 TexCoords;\n"
    "uniform sampler2D U_Texture;\n"
    "void main()\n"
    "{\n"
    "vec3 colour = texture(U_Texture, TexCoords).rgb;\n"
    "FragColour = vec4(colour, 1.0f);\n"
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
        /* -0.5f, -0.5f, 0.0f, 0.0f, 0.0f,
         0.5f, -0.5f, 0.0f, 1.0f, 0.0f,
         0.0f,  0.5f, 0.0f, 0.5f, 1.0f */

         0.5f,  0.5f, 0.0f, 1.0f, 1.0f,
         0.5f, -0.5f, 0.0f, 1.0f, 0.0f,
        -0.5f,  0.5f, 0.0f, 0.0f, 1.0f,
         0.5f, -0.5f, 0.0f, 1.0f, 0.0f,
        -0.5f, -0.5f, 0.0f, 0.0f, 0.0f,
        -0.5f,  0.5f, 0.0f, 0.0f, 1.0f 
    };

    float texCoords[] =
    {
        0.0f, 0.0f,
        1.0f, 0.0f,
        0.5f, 1.0f
    };

    float matrix[4][4] =
    {
        1.0f, 0.0f, 0.0f, 0.0f, 
        0.0f, 1.0f, 0.0f, 0.0f, 
        0.0f, 0.0f, 1.0f, 0.0f, 
        0.0f, 0.0f, 0.0f, 1.0f
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

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);

    glBindBuffer(GL_ARRAY_BUFFER, 0);

    glBindVertexArray(0);

    // Texture stuff
    int width, height, channels;

    stbi_set_flip_vertically_on_load(1);
    unsigned char* data = stbi_load("Face.png", &width, &height, &channels, 0);

    unsigned int texture;
    glGenTextures(1, &texture);
    glBindTexture(GL_TEXTURE_2D, texture);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);

    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
    glBindTexture(GL_TEXTURE_2D, 0);

    stbi_image_free(data);

    glUseProgram(program);
    glUniform1i(glGetUniformLocation(program, "U_Texture"), 0);
    glUniformMatrix4fv(glGetUniformLocation(program, "U_Projection"), 1, GL_FALSE, &matrix[0][0]);


    while(!glfwWindowShouldClose(window))
    {
        glClear(GL_COLOR_BUFFER_BIT);
        
        glActiveTexture(GL_TEXTURE0);
        glBindTexture(GL_TEXTURE_2D, texture);

        glUseProgram(program);
        glBindVertexArray(vao);
        glDrawArrays(GL_TRIANGLES, 0, 6);

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glDeleteVertexArrays(1, &vao);
    glDeleteProgram(program);
    glDeleteBuffers(1, &vbo);

    glfwTerminate();
    return 0;
}