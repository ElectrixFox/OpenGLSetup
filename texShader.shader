#shader Vertex
#version 430 core

layout(location = 0) in vec3 position;
layout(location = 1) in vec2 texCoord;

out vec2 V_TexCoord;

void main(void)
{
	gl_Position = vec4(position.x, position.y, position.z, 1);
	V_TexCoord = texCoord;
};

#shader Fragment
#version 430 core

layout(location = 0) out vec4 colour;

in vec2 V_TexCoord;

uniform sampler2D U_Texture;

void main()
{
	vec4 texColour = texture(U_Texture, V_TexCoord);
	colour = texColour;
};