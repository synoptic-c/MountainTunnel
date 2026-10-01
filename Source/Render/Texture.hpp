#pragma once
#include<string>
#include<string_view>
#include<cmath>
#include<glad/glad.h>
#include<stb_image.h>
#include"Util/Log.hpp"
namespace MountainTunnel
{
	class Texture
	{
	private:
		unsigned int _texture;
		static unsigned int LoadTexture(std::string_view path);
		static unsigned int CreateTexture(int width, int height, unsigned int internalformat, unsigned int format, unsigned char* data);
	public:
		Texture(std::string_view path);
		Texture(int width, int height, unsigned int internalformat = GL_RGBA8, unsigned int format = GL_RGBA, unsigned char* data = nullptr);
		~Texture();
		Texture(const MountainTunnel::Texture&) = delete;
		MountainTunnel::Texture& operator=(const MountainTunnel::Texture&) = delete;
		Texture(MountainTunnel::Texture&& other) noexcept;
		MountainTunnel::Texture& operator=(MountainTunnel::Texture&& other) noexcept;
		void Bind(unsigned int unit) const;
		unsigned int GetTexture() const;
	};
}