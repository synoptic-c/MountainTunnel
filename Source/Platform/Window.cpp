#include"Window.hpp"
MountainTunnel::Window::Window(int width, int height, std::string_view title) : _window{}
{
	_window = glfwCreateWindow(width, height, std::string(title).c_str(), nullptr, nullptr);
	if (!_window)
	{
		MountainTunnel::Log::Error(FILE_LINE, "Failed to create window");
		return;
	}
	glfwMakeContextCurrent(_window);
	glfwSetFramebufferSizeCallback(_window, [](GLFWwindow* window, int width, int height)
	{
		glViewport(0, 0, width, height);
	});
}
MountainTunnel::Window::~Window()
{
	if (_window)
	{
		glfwDestroyWindow(_window);
	}
}
bool MountainTunnel::Window::WindowShouldClose() const
{
	if (_window)
	{
		return glfwWindowShouldClose(_window);
	}
	return true;
}
void MountainTunnel::Window::PollEvents() const
{
	if (_window)
	{
		glfwPollEvents();
	}
}
void MountainTunnel::Window::SwapBuffers() const
{
	if (_window)
	{
		glfwSwapBuffers(_window);
	}
}
bool MountainTunnel::Window::GetKey(int key) const
{
	if (_window)
	{
		return glfwGetKey(_window, key) == GLFW_PRESS;
	}
	return bool{};
}
void MountainTunnel::Window::SetInputMode(int value) const
{
	if (_window)
	{
		glfwSetInputMode(_window, GLFW_CURSOR, value);
	}
}
bool MountainTunnel::Window::GetMouseButton(int button) const
{
	if (_window)
	{
		return glfwGetMouseButton(_window, button) == GLFW_PRESS;
	}
	return bool{};
}
glm::vec2 MountainTunnel::Window::GetCursorPos() const
{
	if (_window)
	{
		double xpos;
		double ypos;
		glfwGetCursorPos(_window, &xpos, &ypos);
		return glm::vec2(xpos, ypos);
	}
	return glm::vec2{};
}
int MountainTunnel::Window::GetInputMode(int mode) const
{
	if (_window)
	{
		return glfwGetInputMode(_window, mode);
	}
	return int{};
}
glm::ivec2 MountainTunnel::Window::GetFramebufferSize() const
{
	if (_window)
	{
		int width;
		int height;
		glfwGetFramebufferSize(_window, &width, &height);
		return glm::ivec2(width, height);
	}
	return glm::ivec2{};
}