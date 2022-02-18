#shader Vertex

#version 430 core
layout (location = 0) in vec3 aPos;

void main()
{
   gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);
}


#shader Fragment
#version 430 core
out vec4 FragColour;
uniform vec4 U_Colour;

void main()
{
   FragColour = U_Colour;
}