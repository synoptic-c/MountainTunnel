#include"Object.hpp"
MountainTunnel::Object::Object(const std::vector<std::vector<MountainTunnel::Vertex>>& vertices, const std::vector<std::vector<unsigned int>>& indices, const std::vector<std::string>& texturesPath, const std::vector<glm::vec3>& positions, const std::vector<glm::vec3>& scales)
{
	_meshes.reserve(vertices.size());
	_textures.reserve(texturesPath.size());
	for (unsigned int i = 0; i < vertices.size(); i++)
	{
		_meshes.emplace_back(vertices[i], indices[i]);
	}
	for (const std::string& texturePath : texturesPath)
	{
		_textures.emplace_back(texturePath);
	}
	_positions = positions;
	_scales = scales;
}
void MountainTunnel::Object::Render()
{
	for (unsigned int i = 0; i < _meshes.size(); i++)
	{
		_meshes[i].Bind();
		_textures[i].Bind({});
		_meshes[i].Draw();
	}
}
const std::vector<glm::vec3>& MountainTunnel::Object::GetPositions() const
{
	return _positions;
}
const std::vector<glm::vec3>& MountainTunnel::Object::GetScales() const
{
	return _scales;
}