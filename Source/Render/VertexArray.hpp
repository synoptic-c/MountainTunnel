#pragma once
#include<glad/glad.h>
namespace MountainTunnel
{
	class VertexArray
	{
	private:
		unsigned int _vertexArray;
	public:
		VertexArray();
		~VertexArray();
		VertexArray(const MountainTunnel::VertexArray&) = delete;
		MountainTunnel::VertexArray& operator=(const MountainTunnel::VertexArray&) = delete;
		VertexArray(MountainTunnel::VertexArray&& other) noexcept;
		MountainTunnel::VertexArray& operator=(MountainTunnel::VertexArray&& other) noexcept;
		void VertexArrayAttribFormat(unsigned int attribindex, int size, unsigned int type, unsigned char normalized, unsigned int relativeoffset) const;
		void VertexArrayAttribBinding(unsigned int attribindex, unsigned int bindingindex) const;
		void EnableVertexArrayAttrib(unsigned int index) const;
		void VertexArrayVertexBuffer(unsigned int bindingindex, unsigned int buffer, GLintptr offset, int stride) const;
		void VertexArrayElementBuffer(unsigned int buffer) const;
		void DrawArrays(int count) const;
		void DrawElements(int count) const;
		void Bind() const;
	};
}