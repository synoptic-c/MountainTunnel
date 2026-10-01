#include"IndexBuffer.hpp"
MountainTunnel::IndexBuffer::IndexBuffer() : _indexBuffer{}
{
	glCreateBuffers(1, &_indexBuffer);
}
MountainTunnel::IndexBuffer::~IndexBuffer()
{
	if (_indexBuffer)
	{
		glDeleteBuffers(1, &_indexBuffer);
	}
}
MountainTunnel::IndexBuffer::IndexBuffer(MountainTunnel::IndexBuffer&& other) noexcept
{
	_indexBuffer = other._indexBuffer;
	other._indexBuffer = {};
}
MountainTunnel::IndexBuffer& MountainTunnel::IndexBuffer::operator=(MountainTunnel::IndexBuffer&& other) noexcept
{
	if (this != &other)
	{
		if (_indexBuffer)
		{
			glDeleteBuffers(1, &_indexBuffer);
		}
		_indexBuffer = other._indexBuffer;
		other._indexBuffer = {};
	}
	return *this;
}
void MountainTunnel::IndexBuffer::NamedBufferStorage(GLsizeiptr size, const void* data, unsigned int flags) const
{
	if (_indexBuffer)
	{
		glNamedBufferStorage(_indexBuffer, size, data, flags);
	}
}
unsigned int MountainTunnel::IndexBuffer::GetIndexBuffer() const
{
	if (_indexBuffer)
	{
		return _indexBuffer;
	}
	return {};
}