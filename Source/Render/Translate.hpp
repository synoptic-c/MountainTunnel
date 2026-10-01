#pragma once
#include<glm/ext/vector_float3.hpp>
#include<nlohmann/json.hpp>
namespace MountainTunnel
{
	struct Translate
	{
		glm::vec3 position;
		glm::vec3 scale;
		glm::vec3 axis;
		float angle;
	};
	void from_json(const nlohmann::json& json, MountainTunnel::Translate& translate);
}