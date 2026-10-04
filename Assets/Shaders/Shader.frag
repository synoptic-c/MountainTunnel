#version 450 core
out vec4 FragColor;
in vec2 textureUv;
uniform sampler2D textureColor;
void main()
{
	FragColor = texture(textureColor, textureUv);
}