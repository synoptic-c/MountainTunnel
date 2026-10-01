#include"VertexBuffer.hpp"
MountainTunnel::VertexBuffer::VertexBuffer() : _vertexBuffer{}
{
	glCreateBuffers(1, &_vertexBuffer);
}
MountainTunnel::VertexBuffer::~VertexBuffer()
{
	if (_vertexBuffer)
	{
		glDeleteBuffers(1, &_vertexBuffer);
	}
}
MountainTunnel::VertexBuffer::VertexBuffer(MountainTunnel::VertexBuffer&& other) noexcept
{
	_vertexBuffer = other._vertexBuffer;
	other._vertexBuffer = {};
}
MountainTunnel::VertexBuffer& MountainTunnel::VertexBuffer::operator=(MountainTunnel::VertexBuffer&& other) noexcept
{
	if (this != &other)
	{
		if (_vertexBuffer)
		{
			glDeleteBuffers(1, &_vertexBuffer);
		}
		_vertexBuffer = other._vertexBuffer;
		other._vertexBuffer = {};
	}
	return *this;
}
void MountainTunnel::VertexBuffer::NamedBufferStorage(GLsizeiptr size, const void* data, unsigned int flags) const
{
	if (_vertexBuffer)
	{
		glNamedBufferStorage(_vertexBuffer, size, data, flags);
	}
}
unsigned int MountainTunnel::VertexBuffer::GetVertexBuffer() const
{
	if (_vertexBuffer)
	{
		return _vertexBuffer;
	}
	return {};
}