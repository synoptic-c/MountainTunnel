#include"VertexArray.hpp"
MountainTunnel::VertexArray::VertexArray() : _vertexArray{}
{
	glCreateVertexArrays(1, &_vertexArray);
}
MountainTunnel::VertexArray::~VertexArray()
{
	if (_vertexArray)
	{
		glDeleteVertexArrays(1, &_vertexArray);
	}
}
MountainTunnel::VertexArray::VertexArray(MountainTunnel::VertexArray&& other) noexcept
{
	_vertexArray = other._vertexArray;
	other._vertexArray = {};
}
MountainTunnel::VertexArray& MountainTunnel::VertexArray::operator=(MountainTunnel::VertexArray&& other) noexcept
{
	if (this != &other)
	{
		if (_vertexArray)
		{
			glDeleteVertexArrays(1, &_vertexArray);
		}
		_vertexArray = other._vertexArray;
		other._vertexArray = {};
	}
	return *this;
}
void MountainTunnel::VertexArray::VertexArrayAttribFormat(unsigned int attribindex, int size, unsigned int type, unsigned char normalized, unsigned int relativeoffset) const
{
	if (_vertexArray)
	{
		glVertexArrayAttribFormat(_vertexArray, attribindex, size, type, normalized, relativeoffset);
	}
}
void MountainTunnel::VertexArray::VertexArrayAttribBinding(unsigned int attribindex, unsigned int bindingindex) const
{
	if (_vertexArray)
	{
		glVertexArrayAttribBinding(_vertexArray, attribindex, bindingindex);
	}
}
void MountainTunnel::VertexArray::EnableVertexArrayAttrib(unsigned int index) const
{
	if (_vertexArray)
	{
		glEnableVertexArrayAttrib(_vertexArray, index);
	}
}
void MountainTunnel::VertexArray::VertexArrayVertexBuffer(unsigned int bindingindex, unsigned int buffer, GLintptr offset, int stride) const
{
	if (_vertexArray)
	{
		glVertexArrayVertexBuffer(_vertexArray, bindingindex, buffer, offset, stride);
	}
}
void MountainTunnel::VertexArray::VertexArrayElementBuffer(unsigned int buffer) const
{
	if (_vertexArray)
	{
		glVertexArrayElementBuffer(_vertexArray, buffer);
	}
}
void MountainTunnel::VertexArray::DrawArrays(int count) const
{
	glDrawArrays(GL_TRIANGLES, 0, count);
}
void MountainTunnel::VertexArray::DrawElements(int count) const
{
	glDrawElements(GL_TRIANGLES, count, GL_UNSIGNED_INT, nullptr);
}
void MountainTunnel::VertexArray::Bind() const
{
	if (_vertexArray)
	{
		glBindVertexArray(_vertexArray);
	}
}