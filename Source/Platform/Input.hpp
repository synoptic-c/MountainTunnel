#pragma once
#include<glad/glad.h>
#include<glfw/glfw3.h>
#include"Platform/Window.hpp"
namespace MountainTunnel
{
	class Input
	{
	private:
		bool _moveForward;
		bool _moveBack;
		bool _moveLeft;
		bool _moveRight;
		bool _interact;
		bool _pause;
	public:
		Input();
		void Update(const MountainTunnel::Window& window);
		bool GetMoveForward() const;
		bool GetMoveBack() const;
		bool GetMoveLeft() const;
		bool GetMoveRight() const;
		bool GetInteract() const;
		bool GetPause() const;
	};
}