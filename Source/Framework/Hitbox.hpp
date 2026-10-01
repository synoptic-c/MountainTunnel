#pragma once
#include<glm/ext/vector_float3.hpp>
#include<nlohmann/json.hpp>
namespace MountainTunnel
{
	struct Hitbox
	{
		glm::vec3 range;
	};
	void from_json(const nlohmann::json& json, MountainTunnel::Hitbox& hitbox);
}