#pragma once
#include<vector>
#include<string>
#include<glm/ext/vector_float3.hpp>
#include"Render/Mesh.hpp"
#include"Render/Texture.hpp"
namespace MountainTunnel
{
	class Object
	{
	private:
		std::vector<MountainTunnel::Mesh> _meshes;
		std::vector<MountainTunnel::Texture> _textures;
		std::vector<glm::vec3> _positions;
		std::vector<glm::vec3> _scales;
	public:
		Object(const std::vector<std::vector<MountainTunnel::Vertex>>& vertices, const std::vector<std::vector<unsigned int>>& indices, const std::vector<std::string>& texturesPath, const std::vector<glm::vec3>& positions, const std::vector<glm::vec3>& scales);
		void Render();
		const std::vector<glm::vec3>& GetPositions() const;
		const std::vector<glm::vec3>& GetScales() const;
	};
}