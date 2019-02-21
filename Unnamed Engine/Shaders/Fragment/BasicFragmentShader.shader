#version 450 core

out vec4 FragColor;

in vec3 ourColor;
in vec2 TexCoord;
in float isTexture;

uniform sampler2D ourTexture;

void main()
{
	if (isTexture > 0.0)
	{
		FragColor = texture(ourTexture, TexCoord);

		return;
	}

	FragColor = vec4(ourColor, 1.0f);
}