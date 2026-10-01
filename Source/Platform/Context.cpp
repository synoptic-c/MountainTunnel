#include"Context.hpp"
MountainTunnel::Context::Context(int major, int minor)
{
	if (!glfwInit())
	{
		MountainTunnel::Log::Error(FILE_LINE, "Failed to init glfw");
		return;
	}
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, major);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, minor);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	stbi_set_flip_vertically_on_load(true);
}
MountainTunnel::Context::~Context()
{
	glfwTerminate();
}
void MountainTunnel::Context::LoadGLLoader() const
{
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		MountainTunnel::Log::Error(FILE_LINE, "Failed to init glad");
		return;
	}
}