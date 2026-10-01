#pragma once
#include<glm/ext/vector_float3.hpp>
#include<glm/ext/vector_float2.hpp>
#include<nlohmann/json.hpp>
namespace MountainTunnel
{
	struct Vertex
	{
		glm::vec3 position;
		glm::vec2 textureUv;
		glm::vec3 normal;
	};
	void from_json(const nlohmann::json& json, MountainTunnel::Vertex& vertex);
}