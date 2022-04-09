#shader Vertex

#version 400 core
layout (location = 0) in vec3 aPos;
uniform mat4 U_Transform;

void main()
{
   vec4 position = vec4(aPos.x, aPos.y, aPos.z, 1.0) * U_Transform;
   gl_Position = position;
}


#shader Fragment
#version 400 core
out vec4 FragColour;
uniform vec4 U_Colour;

void main()
{
   FragColour = U_Colour;
}
