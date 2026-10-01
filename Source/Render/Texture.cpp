#include"Texture.hpp"
unsigned int MountainTunnel::Texture::LoadTexture(std::string_view path)
{
	int width;
	int height;
	int comp;
	unsigned char* data = stbi_load(path.data(), &width, &height, &comp, 0);
	if (!data)
	{
		MountainTunnel::Log::ErrorFile(FILE_LINE, path, "Failed to load image");
		return {};
	}
	unsigned int internalformat = GL_RGBA8;
	unsigned int format = GL_RGBA;
	if (comp == STBI_grey)
	{
		internalformat = GL_R8;
		format = GL_RED;
	}
	if (comp == STBI_grey_alpha)
	{
		internalformat = GL_RG8;
		format = GL_RG;
	}
	if (comp == STBI_rgb)
	{
		internalformat = GL_RGB8;
		format = GL_RGB;
	}
	if (comp == STBI_rgb_alpha)
	{
		internalformat = GL_RGBA8;
		format = GL_RGBA;
	}
	unsigned int texture = MountainTunnel::Texture::CreateTexture(width, height, internalformat, format, data);
	stbi_image_free(data);
	return texture;
}
unsigned int MountainTunnel::Texture::CreateTexture(int width, int height, unsigned int internalformat, unsigned int format, unsigned char* data)
{
	unsigned int texture;
	glCreateTextures(GL_TEXTURE_2D, 1, &texture);
	glTextureStorage2D(texture, 1 + std::log2(std::max(width, height)), internalformat, width, height);
	glTextureSubImage2D(texture, 0, 0, 0, width, height, format, GL_UNSIGNED_BYTE, data);
	glTextureParameteri(texture, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTextureParameteri(texture, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTextureParameteri(texture, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTextureParameteri(texture, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
	glGenerateTextureMipmap(texture);
	return texture;
}
MountainTunnel::Texture::Texture(std::string_view path)
{
	_texture = MountainTunnel::Texture::LoadTexture(path);
}
MountainTunnel::Texture::Texture(int width, int height, unsigned int internalformat, unsigned int format, unsigned char* data)
{
	_texture = MountainTunnel::Texture::CreateTexture(width, height, internalformat, format, data);
}
MountainTunnel::Texture::~Texture()
{
	if (_texture)
	{
		glDeleteTextures(1, &_texture);
	}
}
MountainTunnel::Texture::Texture(MountainTunnel::Texture&& other) noexcept
{
	_texture = other._texture;
	other._texture = {};
}
MountainTunnel::Texture& MountainTunnel::Texture::operator=(MountainTunnel::Texture&& other) noexcept
{
	if (this != &other)
	{
		if (_texture)
		{
			glDeleteTextures(1, &_texture);
		}
		_texture = other._texture;
		other._texture = {};
	}
	return *this;
}
void MountainTunnel::Texture::Bind(unsigned int unit) const
{
	if (_texture)
	{
		glBindTextureUnit(unit, _texture);
	}
}
unsigned int MountainTunnel::Texture::GetTexture() const
{
	if (_texture)
	{
		return _texture;
	}
	return {};
}