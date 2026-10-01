#version 450 core
layout(location = 0) in vec3 v_position;
layout(location = 1) in vec2 v_textureUv;
layout(location = 2) in vec3 v_normal;
out vec2 f_textureUv;
out vec3 f_fragPosition;
out vec3 f_normal;
uniform mat4 u_projection;
uniform mat4 u_view;
uniform mat4 u_model;
void main()
{
	gl_Position = u_projection * u_view * u_model * vec4(v_position, 1.0);
	f_textureUv = v_textureUv;
	f_fragPosition = vec3(u_model * vec4(v_position, 1.0));
	f_normal = transpose(inverse(mat3(u_model))) * v_normal;
}