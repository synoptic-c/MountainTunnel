#include"Input.hpp"
MountainTunnel::Input::Input() : _moveForward{}, _moveBack{}, _moveLeft{}, _moveRight{}, _interact{}, _pause{}
{

}
void MountainTunnel::Input::Update(const MountainTunnel::Window& window)
{
	_moveForward = window.GetKey(GLFW_KEY_W);
	_moveBack = window.GetKey(GLFW_KEY_S);
	_moveLeft = window.GetKey(GLFW_KEY_A);
	_moveRight = window.GetKey(GLFW_KEY_D);
	_pause = window.GetKey(GLFW_KEY_ESCAPE);
	_interact = window.GetMouseButton(GLFW_MOUSE_BUTTON_LEFT);
	if (_interact)
	{
		window.SetInputMode(GLFW_CURSOR_DISABLED);
	}
	if (_pause)
	{
		window.SetInputMode(GLFW_CURSOR_NORMAL);
	}
}
bool MountainTunnel::Input::GetMoveForward() const
{
	return _moveForward;
}
bool MountainTunnel::Input::GetMoveBack() const
{
	return _moveBack;
}
bool MountainTunnel::Input::GetMoveLeft() const
{
	return _moveLeft;
}
bool MountainTunnel::Input::GetMoveRight() const
{
	return _moveRight;
}
bool MountainTunnel::Input::GetInteract() const
{
	return _interact;
}
bool MountainTunnel::Input::GetPause() const
{
	return _pause;
}