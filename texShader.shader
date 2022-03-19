#shader Vertex
#version 430 core

layout(location = 0) in vec3 position;
layout(location = 1) in vec2 texCoord;

uniform mat4 U_Transform;

uniform vec4 U_Trans;

out vec2 V_TexCoord;

mat4 GetMatrix()
{
	mat4 mat = 
	{
		{1.0f, 0.0f, 0.0f, U_Trans.x/960},
		{0.0f, 1.0f, 0.0f, U_Trans.y/540},
		{0.0f, 0.0f, 1.0f, 0.0f},
		{0.0f, 0.0f, 0.0f, 1.0f} 
	};

	return mat;
}

void main(void)
{
	gl_Position = vec4(position.x, position.y, position.z, 1) * GetMatrix();
	V_TexCoord = texCoord;
};

#shader Fragment
#version 430 core

layout(location = 0) out vec4 colour;

in vec2 V_TexCoord;

uniform sampler2D U_Texture;


uniform float U_Tex;
uniform vec4 U_Colour;

void main()
{
	vec4 texColour;

	if(U_Tex == 1)
		texColour = texture(U_Texture, V_TexCoord);
	else
		texColour = U_Colour;
	
	colour = texColour;
};