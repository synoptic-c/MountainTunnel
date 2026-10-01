#version 450 core
#define POINT_LIGHT_COUNT 2
out vec4 FragColor;
in vec2 f_textureUv;
in vec3 f_fragPosition;
in vec3 f_normal;
uniform sampler2D u_diffuse;
uniform sampler2D u_specular;
uniform vec3 u_viewPosition;
uniform float u_shininess;
struct OrientLight
{
	vec3 direction;
	vec3 ambient;
	vec3 diffuse;
	vec3 specular;
};
struct PointLight
{
	vec3 position;
	vec3 ambient;
	vec3 diffuse;
	vec3 specular;
	float constant;
	float linear;
	float quadratic;
};
struct SpotLight
{
	vec3 position;
	vec3 direction;
	vec3 ambient;
	vec3 diffuse;
	vec3 specular;
	float cutOff;
	float outerCutOff;
	float constant;
	float linear;
	float quadratic;
};
uniform OrientLight u_orientLight;
uniform PointLight u_pointLight[POINT_LIGHT_COUNT];
uniform SpotLight u_spotLight;
vec4 CalcOrientLight(const in OrientLight orientLight, vec3 normal, vec3 viewDirection)
{
	vec3 lightDirection = normalize(-orientLight.direction);
	vec3 reflectDirection = reflect(-lightDirection, normal);
	vec4 ambient = vec4(orientLight.ambient, 1.0) * texture(u_diffuse, f_textureUv);
	vec4 diffuse = max(dot(normal, lightDirection), 0.0) * vec4(orientLight.diffuse, 1.0) * texture(u_diffuse, f_textureUv);
	vec4 specular = pow(max(dot(viewDirection, reflectDirection), 0.0), u_shininess) * vec4(orientLight.specular, 1.0) * texture(u_specular, f_textureUv);
	return ambient + diffuse + specular;
}
vec4 CalcPointLight(const in PointLight pointLight, vec3 normal, vec3 fragPosition, vec3 viewDirection)
{
	vec3 lightDirection = normalize(pointLight.position - fragPosition);
	vec3 reflectDirection = reflect(-lightDirection, normal);
	float distance = length(pointLight.position - fragPosition);
	float attenuation = 1.0 / (pointLight.constant + pointLight.linear * distance + pointLight.quadratic * (distance * distance));
	vec4 ambient = vec4(pointLight.ambient, 1.0) * texture(u_diffuse, f_textureUv);
	vec4 diffuse = max(dot(normal, lightDirection), 0.0) * vec4(pointLight.diffuse, 1.0) * texture(u_diffuse, f_textureUv);
	vec4 specular = pow(max(dot(viewDirection, reflectDirection), 0.0), u_shininess) * vec4(pointLight.specular, 1.0) * texture(u_specular, f_textureUv);
	ambient *= attenuation;
	diffuse *= attenuation;
	specular *= attenuation;
	return ambient + diffuse + specular;
}
vec4 CalcSpotLight(const in SpotLight spotLight, vec3 normal, vec3 fragPosition, vec3 viewDirection)
{
	vec3 lightDirection = normalize(spotLight.position - fragPosition);
	vec3 reflectDirection = reflect(-lightDirection, normal);
	float distance = length(spotLight.position - normal);
	float attenuation = 1.0 / (spotLight.constant + spotLight.linear * distance + spotLight.quadratic * (distance * distance));
	float theta = dot(lightDirection, normalize(-spotLight.direction));
	float epsilon = spotLight.cutOff - spotLight.outerCutOff;
	float intensity = clamp((theta - spotLight.outerCutOff) / epsilon, 0.0, 1.0);
	vec4 ambient = vec4(spotLight.ambient, 1.0) * texture(u_diffuse, f_textureUv);
	vec4 diffuse = max(dot(normal, lightDirection), 0.0) * vec4(spotLight.diffuse, 1.0) * texture(u_diffuse, f_textureUv);
	vec4 specular = pow(max(dot(viewDirection, reflectDirection), 0.0), u_shininess) * vec4(spotLight.ambient, 1.0) * texture(u_specular, f_textureUv);
	ambient *= attenuation * intensity;
	diffuse *= attenuation * intensity;
	specular *= attenuation * intensity;
	return ambient + diffuse + specular;
}
void main()
{
	vec3 normal = normalize(f_normal);
	vec3 viewDirection = normalize(u_viewPosition - f_fragPosition);
	FragColor = CalcOrientLight(u_orientLight, normal, viewDirection);
	for (uint i = 0; i < POINT_LIGHT_COUNT; i++)
	{
		FragColor += CalcPointLight(u_pointLight[i], normal, f_fragPosition, viewDirection);
	}
	FragColor += CalcSpotLight(u_spotLight, normal, f_fragPosition, viewDirection);
}