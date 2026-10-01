#include"RenderBuffer.hpp"
MountainTunnel::RenderBuffer::RenderBuffer() : _renderBuffer{}
{
	glCreateRenderbuffers(1, &_renderBuffer);
}
MountainTunnel::RenderBuffer::~RenderBuffer()
{
	if (_renderBuffer)
	{
		glDeleteRenderbuffers(1, &_renderBuffer);
	}
}
MountainTunnel::RenderBuffer::RenderBuffer(MountainTunnel::RenderBuffer&& other) noexcept
{
	_renderBuffer = other._renderBuffer;
	other._renderBuffer = {};
}
MountainTunnel::RenderBuffer& MountainTunnel::RenderBuffer::operator=(MountainTunnel::RenderBuffer&& other) noexcept
{
	if (this != &other)
	{
		if (_renderBuffer)
		{
			glDeleteRenderbuffers(1, &_renderBuffer);
		}
		_renderBuffer = other._renderBuffer;
		other._renderBuffer = {};
	}
	return *this;
}
void MountainTunnel::RenderBuffer::NamedRenderbufferStorage(unsigned int internalformat, int width, int height) const
{
	if (_renderBuffer)
	{
		glNamedRenderbufferStorage(_renderBuffer, internalformat, width, height);
	}
}
unsigned int MountainTunnel::RenderBuffer::GetRenderBuffer() const
{
	if (_renderBuffer)
	{
		return _renderBuffer;
	}
	return {};
}
void MountainTunnel::RenderBuffer::BindRenderBuffer() const
{
	if (_renderBuffer)
	{
		glBindRenderbuffer(GL_RENDERBUFFER, _renderBuffer);
	}
}