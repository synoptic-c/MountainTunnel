#pragma once
#include<glad/glad.h>
#include<glfw/glfw3.h>
#include<stb_image.h>
#include"Util/Log.hpp"
namespace MountainTunnel
{
	class Context
	{
	private:

	public:
		Context(int major, int minor);
		~Context();
		Context(const MountainTunnel::Context&) = delete;
		MountainTunnel::Context& operator=(const MountainTunnel::Context&) = delete;
		void LoadGLLoader() const;
	};
}