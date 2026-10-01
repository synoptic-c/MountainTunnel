#pragma once
#include<vector>
#include<glm/ext/vector_float3.hpp>
#include"Framework/Hitbox.hpp"
namespace MountainTunnel
{
	class Collision
	{
	private:

	public:
		static void Process(glm::vec3& positionSelf, const std::vector<glm::vec3>& positionOther, MountainTunnel::Hitbox hitboxSelf, const std::vector<MountainTunnel::Hitbox>& hitboxOther, glm::vec3& speedSelf, glm::vec3 axisCollision);
	};
}