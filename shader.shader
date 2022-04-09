#shader Vertex

#version 430 core
layout (location = 0) in vec3 aPos;
uniform mat4 U_Transform;

void main()
{
   vec4 position = vec4(aPos.x, aPos.y, aPos.z, 1.0);
   gl_Position = position * U_Transform;
}


#shader Fragment
#version 430 core
out vec4 FragColour;
uniform vec4 U_Colour;

void main()
{
   FragColour = U_Colour;
}