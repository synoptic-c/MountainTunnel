#pragma once
#include<glad/glad.h>
namespace MountainTunnel
{
	class IndexBuffer
	{
	private:
		unsigned int _indexBuffer;
	public:
		IndexBuffer();
		~IndexBuffer();
		IndexBuffer(const MountainTunnel::IndexBuffer&) = delete;
		MountainTunnel::IndexBuffer& operator=(const MountainTunnel::IndexBuffer&) = delete;
		IndexBuffer(MountainTunnel::IndexBuffer&& other) noexcept;
		MountainTunnel::IndexBuffer& operator=(MountainTunnel::IndexBuffer&& other) noexcept;
		void NamedBufferStorage(GLsizeiptr size, const void* data, unsigned int flags) const;
		unsigned int GetIndexBuffer() const;
	};
}