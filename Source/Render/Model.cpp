#include"Model.hpp"
MountainTunnel::Model::Model(std::string_view path)
{
	Assimp::Importer importer;
	const aiScene* scene = importer.ReadFile(std::string(path), aiProcess_Triangulate | aiProcess_FlipUVs | aiProcess_GenSmoothNormals | aiProcess_CalcTangentSpace);
	if (!scene || scene->mFlags & AI_SCENE_FLAGS_INCOMPLETE || !scene->mRootNode)
	{
		MountainTunnel::Log::Error(FILE_LINE, importer.GetErrorString());
		return;
	}
	std::unordered_set<std::string> cacheTextures;
	ProcessNode(scene->mRootNode, scene, cacheTextures);
}
void MountainTunnel::Model::ProcessNode(aiNode* node, const aiScene* scene, std::unordered_set<std::string>& cacheTextures)
{
	for (unsigned int i = 0; i < node->mNumMeshes; i++)
	{
		aiMesh* mesh = scene->mMeshes[node->mMeshes[i]];
		ProcessMesh(mesh, scene, cacheTextures);
	}
	for (unsigned int i = 0; i < node->mNumChildren; i++)
	{
		ProcessNode(node->mChildren[i], scene, cacheTextures);
	}
}
void MountainTunnel::Model::ProcessMesh(aiMesh* mesh, const aiScene* scene, std::unordered_set<std::string>& cacheTextures)
{
	std::vector<MountainTunnel::Vertex> vertices;
	std::vector<unsigned int> indices;
	for (unsigned int i = 0; i < mesh->mNumVertices; i++)
	{
		glm::vec3 position(
			mesh->mVertices[i].x,
			mesh->mVertices[i].y,
			mesh->mVertices[i].z
		);
		glm::vec3 normal(
			mesh->mVertices[i].x,
			mesh->mVertices[i].y,
			mesh->mVertices[i].z
		);
		glm::vec2 textureUv{};
		if (mesh->mTextureCoords[0])
		{
			textureUv.x = mesh->mTextureCoords[0][i].x;
			textureUv.y = mesh->mTextureCoords[0][i].y;
		}
		vertices.emplace_back(MountainTunnel::Vertex{ position, textureUv, normal });
	}
	for (unsigned int i = 0; i < mesh->mNumFaces; i++)
	{
		aiFace face = mesh->mFaces[i];
		for (unsigned int j = 0; j < face.mNumIndices; j++)
		{
			indices.emplace_back(face.mIndices[j]);
		}
	}
	if (mesh->mMaterialIndex >= 0)
	{
		aiMaterial* material = scene->mMaterials[mesh->mMaterialIndex];
		LoadMaterialTextures(material, aiTextureType_DIFFUSE, cacheTextures);
		LoadMaterialTextures(material, aiTextureType_SPECULAR, cacheTextures);
	}
	_meshes.emplace_back(vertices, indices);
}
void MountainTunnel::Model::LoadMaterialTextures(aiMaterial* material, aiTextureType textureType, std::unordered_set<std::string>& cacheTextures)
{
	for (unsigned int i = 0; i < material->GetTextureCount(textureType); i++)
	{
		aiString path;
		material->GetTexture(textureType, i, &path);
		if (std::unordered_set<std::string>::iterator it = cacheTextures.find(std::string(path.C_Str())); it == cacheTextures.end())
		{
			_textures.emplace_back(path.C_Str());
			cacheTextures.emplace(path.C_Str());
		}
	}
}
void MountainTunnel::Model::Draw() const
{
	for (unsigned int i = 0; i < _textures.size(); i++)
	{
		_textures[i].Bind(i);
	}
	for (const MountainTunnel::Mesh& mesh : _meshes)
	{
		mesh.Bind();
		mesh.Draw();
	}
}