#pragma once
#include<vector>
#include<string>
#include<string_view>
#include<unordered_set>
#include<assimp/Importer.hpp>
#include<assimp/scene.h>
#include<assimp/postprocess.h>
#include<assimp/mesh.h>
#include<assimp/material.h>
#include<glm/ext/vector_float3.hpp>
#include"Render/Mesh.hpp"
#include"Render/Texture.hpp"
#include"Util/Log.hpp"
namespace MountainTunnel
{
	class Model
	{
	private:
		std::vector<MountainTunnel::Mesh> _meshes;
		std::vector<MountainTunnel::Texture> _textures;
	public:
		Model(std::string_view path);
		void ProcessNode(aiNode* node, const aiScene* scene, std::unordered_set<std::string>& cacheTextures);
		void ProcessMesh(aiMesh* mesh, const aiScene* scene, std::unordered_set<std::string>& cacheTextures);
		void LoadMaterialTextures(aiMaterial* material, aiTextureType textureType, std::unordered_set<std::string>& cacheTextures);
		void Draw() const;
	};
}