#version 450 core
layout(location = 0) in vec3 positionVertex;
layout(location = 1) in vec2 textureUvVertex;
out vec2 textureUv;
uniform mat4x4 projection;
uniform mat4x4 view;
uniform mat4x4 model;
void main()
{
	gl_Position = projection * view * model * vec4(positionVertex, 1.0);
	textureUv = textureUvVertex;
}