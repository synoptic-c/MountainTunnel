#pragma once
#include<string_view>
#include<string>
#include<glad/glad.h>
#include<GLFW/glfw3.h>
#include<glm/ext/vector_float2.hpp>
#include<glm/ext/vector_int2.hpp>
#include"Util/Log.hpp"
namespace MountainTunnel
{
	class Window
	{
	private:
		GLFWwindow* _window;
	public:
		Window(int width, int height, std::string_view title);
		~Window();
		Window(const MountainTunnel::Window&) = delete;
		MountainTunnel::Window& operator=(const MountainTunnel::Window&) = delete;
		bool WindowShouldClose() const;
		void PollEvents() const;
		void SwapBuffers() const;
		bool GetKey(int key) const;
		void SetInputMode(int value) const;
		bool GetMouseButton(int button) const;
		glm::vec2 GetCursorPos() const;
		int GetInputMode(int mode) const;
		glm::ivec2 GetFramebufferSize() const;
	};
}