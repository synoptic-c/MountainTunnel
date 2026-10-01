#pragma once
#include<glad/glad.h>
namespace MountainTunnel
{
	class RenderBuffer
	{
	private:
		unsigned int _renderBuffer;
	public:
		RenderBuffer();
		~RenderBuffer();
		RenderBuffer(const MountainTunnel::RenderBuffer&) = delete;
		MountainTunnel::RenderBuffer& operator=(const MountainTunnel::RenderBuffer&) = delete;
		RenderBuffer(MountainTunnel::RenderBuffer&& other) noexcept;
		MountainTunnel::RenderBuffer& operator=(MountainTunnel::RenderBuffer&& other) noexcept;
		void NamedRenderbufferStorage(unsigned int internalformat, int width, int height) const;
		unsigned int GetRenderBuffer() const;
		void BindRenderBuffer() const;
	};
}