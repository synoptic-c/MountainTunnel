#include"Map.hpp"
MountainTunnel::Map::Map(std::string_view path, const std::vector<MountainTunnel::Vertex>& vertices, const std::vector<unsigned int>& indices)
{
	std::ifstream file{ std::string(path) };
	if (!file)
	{
		MountainTunnel::Log::ErrorFile(FILE_LINE, path);
		return;
	}
	nlohmann::json json(nlohmann::json::parse(file));
	_verticesObject.reserve(json["translatesObject"].size());
	_indicesObject.reserve(json["translatesObject"].size());
	for (unsigned int i = 0; i < json["translatesObject"].size(); i++)
	{
		_verticesObject.emplace_back();
		_indicesObject.emplace_back();
		_verticesObject[i].reserve(json["translatesObject"][i].size() * vertices.size());
		_indicesObject[i].reserve(json["translatesObject"][i].size() * indices.size());
		_positionsObject.reserve(_positionsObject.size() + json["translatesObject"][i].size());
		_scalesObject.reserve(_scalesObject.size() + json["translatesObject"][i].size());
		for (unsigned int j = 0; j < json["translatesObject"][i].size(); j++)
		{
			glm::vec3 position(
				json["translatesObject"][i][j]["position"]["x"].get<float>(),
				json["translatesObject"][i][j]["position"]["y"].get<float>(),
				json["translatesObject"][i][j]["position"]["z"].get<float>()
			);
			glm::vec3 scale(
				json["translatesObject"][i][j]["scale"]["x"].get<float>(),
				json["translatesObject"][i][j]["scale"]["y"].get<float>(),
				json["translatesObject"][i][j]["scale"]["z"].get<float>()
			);
			glm::vec3 axis(
				json["translatesObject"][i][j]["axis"]["x"].get<float>(),
				json["translatesObject"][i][j]["axis"]["y"].get<float>(),
				json["translatesObject"][i][j]["axis"]["z"].get<float>()
			);
			float angle = json["translatesObject"][i][j]["angle"].get<float>();
			glm::mat4 model(glm::mat4(1.0f));
			model = glm::translate(model, position);
			model = glm::scale(model, scale);
			model = glm::rotate(model, glm::radians(angle), scale);
			_positionsObject.emplace_back(position);
			_scalesObject.emplace_back(scale);
			for (unsigned int k = 0; k < vertices.size(); k++)
			{
				MountainTunnel::Vertex vertex;
				std::memcpy(&vertex, &vertices[k], sizeof(vertex));
				vertex.position = model * glm::vec4(vertex.position, 1.0f);
				_verticesObject[i].emplace_back(vertex);
			}
			for (unsigned int k = 0; k < indices.size(); k++)
			{
				_indicesObject[i].emplace_back(indices[k] + (vertices.size() * j));
			}
		}
	}
	_texturesPathObject.reserve(json["texturesPathObject"].size());
	for (unsigned int i = 0; i < json["texturesPathObject"].size(); i++)
	{
		_texturesPathObject.emplace_back(json["texturesPathObject"][i].get<std::string>());
	}
}
const std::vector<std::vector<MountainTunnel::Vertex>>& MountainTunnel::Map::GetVerticesObject() const
{
	return _verticesObject;
}
const std::vector<std::vector<unsigned int>>& MountainTunnel::Map::GetIndicesObject() const
{
	return _indicesObject;
}
const std::vector<std::string>& MountainTunnel::Map::GetTexturesPathObject() const
{
	return _texturesPathObject;
}
const std::vector<glm::vec3>& MountainTunnel::Map::GetPositionsObject() const
{
	return _positionsObject;
}
const std::vector<glm::vec3>& MountainTunnel::Map::GetScalesObject() const
{
	return _scalesObject;
}