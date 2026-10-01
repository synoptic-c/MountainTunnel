#pragma once
#include<vector>
#include<string_view>
#include<string>
#include<fstream>
#include<cstring>
#include<nlohmann/json.hpp>
#include<glm/ext/matrix_float4x4.hpp>
#include<glm/ext/vector_float3.hpp>
#include<glm/ext/matrix_transform.hpp>
#include<glm/trigonometric.hpp>
#include"Render/Mesh.hpp"
#include"Render/Translate.hpp"
#include"Render/Texture.hpp"
#include"Util/Log.hpp"
namespace MountainTunnel
{
	class Map
	{
	private:
		std::vector<std::vector<MountainTunnel::Vertex>> _verticesObject;
		std::vector<std::vector<unsigned int>> _indicesObject;
		std::vector<std::string> _texturesPathObject;
		std::vector<glm::vec3> _positionsObject;
		std::vector<glm::vec3> _scalesObject;
	public:
		Map(std::string_view path, const std::vector<MountainTunnel::Vertex>& vertices, const std::vector<unsigned int>& indices);
		const std::vector<std::vector<MountainTunnel::Vertex>>& GetVerticesObject() const;
		const std::vector<std::vector<unsigned int>>& GetIndicesObject() const;
		const std::vector<std::string>& GetTexturesPathObject() const;
		const std::vector<glm::vec3>& GetPositionsObject() const;
		const std::vector<glm::vec3>& GetScalesObject() const;
	};
}