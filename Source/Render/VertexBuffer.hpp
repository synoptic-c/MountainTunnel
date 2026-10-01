#pragma once
#include<glad/glad.h>
namespace MountainTunnel
{
	class VertexBuffer
	{
	private:
		unsigned int _vertexBuffer;
	public:
		VertexBuffer();
		~VertexBuffer();
		VertexBuffer(const MountainTunnel::VertexBuffer&) = delete;
		MountainTunnel::VertexBuffer& operator=(const MountainTunnel::VertexBuffer&) = delete;
		VertexBuffer(MountainTunnel::VertexBuffer&& other) noexcept;
		MountainTunnel::VertexBuffer& operator=(MountainTunnel::VertexBuffer&& other) noexcept;
		void NamedBufferStorage(GLsizeiptr size, const void* data, unsigned int flags) const;
		unsigned int GetVertexBuffer() const;
	};
}