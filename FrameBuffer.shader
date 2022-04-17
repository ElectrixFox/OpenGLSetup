#shader Vertex
#version 330 core
layout (location = 0) in vec2 aPos;
layout (location = 1) in vec2 aTexCoords;

out vec2 TexCoords;

void main()
{
    gl_Position = vec4(aPos.x, aPos.y, 0.0, 1.0); 
    TexCoords = aTexCoords;
}

#shader Fragment
#version 330 core
out vec4 FragColour;
  
in vec2 TexCoords;

uniform sampler2D screenTexture;

void main()
{ 
    FragColour = texture(screenTexture, TexCoords);
}
