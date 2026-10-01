#include"Collision.hpp"
void MountainTunnel::Collision::Process(glm::vec3& positionSelf, const std::vector<glm::vec3>& positionOther, MountainTunnel::Hitbox hitboxSelf, const std::vector<MountainTunnel::Hitbox>& hitboxOther, glm::vec3& speedSelf, glm::vec3 axisCollision)
{
	for (unsigned int i = 0; i < positionOther.size(); i++)
	{
		if (positionSelf.z + hitboxSelf.range.z > positionOther[i].z - hitboxOther[i].range.z && axisCollision.z > 0.0f)
		{
			positionSelf.z += positionSelf.z + hitboxSelf.range.z - positionOther[i].z - hitboxOther[i].range.z;
			axisCollision.z = 0.0f;
		}
	}
}