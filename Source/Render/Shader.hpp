#pragma once
#include<string>
#include<string_view>
#include<fstream>
#include<sstream>
#include<glad/glad.h>
#include<glm/ext/matrix_float4x4.hpp>
#include<glm/ext/vector_float3.hpp>
#include<glm/gtc/type_ptr.hpp>
#include"Util/Log.hpp"
namespace MountainTunnel
{
	class Shader
	{
	private:
		unsigned int _program;
		static void LoadShader(std::string_view path, std::string& source);
		static unsigned int CreateShader(std::string_view source, unsigned int type);
	public:
		Shader(std::string_view vertexPath, std::string_view fragmentPath);
		~Shader();
		Shader(const MountainTunnel::Shader&) = delete;
		MountainTunnel::Shader& operator=(const MountainTunnel::Shader&) = delete;
		Shader(MountainTunnel::Shader&& other) noexcept;
		MountainTunnel::Shader& operator=(MountainTunnel::Shader&& other) noexcept;
		void Use() const;
		void SetMat4(std::string_view name, const glm::mat4& value) const;
		void SetVec3(std::string_view name, glm::vec3 value) const;
		void SetFloat(std::string_view name, float value) const;
		void SetUInt(std::string_view name, unsigned int value) const;
	};
}