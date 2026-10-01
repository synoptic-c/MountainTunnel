#pragma once
#include<glad/glad.h>
namespace MountainTunnel
{
	class FrameBuffer
	{
	private:
		unsigned int _frameBuffer;
	public:
		FrameBuffer();
		~FrameBuffer();
		FrameBuffer(const MountainTunnel::FrameBuffer&) = delete;
		MountainTunnel::FrameBuffer& operator=(const MountainTunnel::FrameBuffer&) = delete;
		FrameBuffer(MountainTunnel::FrameBuffer&& other) noexcept;
		MountainTunnel::FrameBuffer& operator=(MountainTunnel::FrameBuffer&& other) noexcept;
		void NamedFramebufferTexture(unsigned int attachment, unsigned int texture, unsigned int level) const;
		void NamedFramebufferRenderbuffer(unsigned int attachment, unsigned int renderbuffertarget, unsigned int renderbuffer) const;
		void BindFramebuffer() const;
	};
}