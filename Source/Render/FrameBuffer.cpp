#include"FrameBuffer.hpp"
MountainTunnel::FrameBuffer::FrameBuffer() : _frameBuffer{}
{
	glCreateFramebuffers(1, &_frameBuffer);
}
MountainTunnel::FrameBuffer::~FrameBuffer()
{
	if (_frameBuffer)
	{
		glDeleteFramebuffers(1, &_frameBuffer);
	}
}
MountainTunnel::FrameBuffer::FrameBuffer(MountainTunnel::FrameBuffer&& other) noexcept
{
	_frameBuffer = other._frameBuffer;
	other._frameBuffer = {};
}
MountainTunnel::FrameBuffer& MountainTunnel::FrameBuffer::operator=(MountainTunnel::FrameBuffer&& other) noexcept
{
	if (this != &other)
	{
		if (_frameBuffer)
		{
			glDeleteFramebuffers(1, &_frameBuffer);
		}
		_frameBuffer = other._frameBuffer;
		other._frameBuffer = {};
	}
	return *this;
}
void MountainTunnel::FrameBuffer::NamedFramebufferTexture(unsigned int attachment, unsigned int texture, unsigned int level) const
{
	if (_frameBuffer)
	{
		glNamedFramebufferTexture(_frameBuffer, attachment, texture, level);
	}
}
void MountainTunnel::FrameBuffer::NamedFramebufferRenderbuffer(unsigned int attachment, unsigned int renderbuffertarget, unsigned int renderbuffer) const
{
	if (_frameBuffer)
	{
		glNamedFramebufferRenderbuffer(_frameBuffer, attachment, renderbuffertarget, renderbuffer);
	}
}
void MountainTunnel::FrameBuffer::BindFramebuffer() const
{
	if (_frameBuffer)
	{
		glBindFramebuffer(GL_FRAMEBUFFER, _frameBuffer);
	}
}