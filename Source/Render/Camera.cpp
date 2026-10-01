#include"Camera.hpp"
MountainTunnel::Camera::Camera() : _position{}, _up{}, _front{}, _last{}, _yaw{}, _pitch{}, _pitchLimit{}, _fov{}, _near{}, _far{}, _projection{}, _view{}
{
	_up = glm::vec3(0.0f, 1.0f, 0.0f);
	_front = glm::vec3(0.0f, 0.0f, 0.0f);
	_pitchLimit = 89.0f;
	_fov = 90.0f;
	_near = 0.1f;
	_far = 100.0f;
}
void MountainTunnel::Camera::Update(const MountainTunnel::Window& window, MountainTunnel::Input input, MountainTunnel::Timer timer)
{
	ProcessMouse(window);
	ProcessMove(window, input, timer);
	SetProjection(window);
	SetView();
}
void MountainTunnel::Camera::ProcessMouse(const MountainTunnel::Window& window)
{
	if (window.GetInputMode(GLFW_CURSOR) != GLFW_CURSOR_DISABLED)
	{
		return;
	}
	glm::vec2 cursorPos(window.GetCursorPos());
	_yaw += cursorPos.x - _last.x;
	_pitch += _last.y - cursorPos.y;
	_last = cursorPos;
	if (_pitch > _pitchLimit)
	{
		_pitch = _pitchLimit;
	}
	if (_pitch < -_pitchLimit)
	{
		_pitch = -_pitchLimit;
	}
	_front = glm::vec3(
		glm::normalize(glm::vec3(glm::cos(glm::radians(_yaw)) * glm::cos(glm::radians(_pitch)),
			glm::sin(glm::radians(_pitch)),
			glm::sin(glm::radians(_yaw)) * glm::cos(glm::radians(_pitch))))
	);
}
void MountainTunnel::Camera::ProcessMove(const MountainTunnel::Window& window, MountainTunnel::Input input, MountainTunnel::Timer timer)
{
	if (window.GetInputMode(GLFW_CURSOR) != GLFW_CURSOR_DISABLED)
	{
		return;
	}
	float delta = timer.GetDelta();
	if (input.GetMoveForward())
	{
		_position += _front * delta;
	}
	if (input.GetMoveBack())
	{
		_position -= _front * delta;
	}
	if (input.GetMoveLeft())
	{
		_position -= glm::normalize(glm::cross(_front, _up)) * delta;
	}
	if (input.GetMoveRight())
	{
		_position += glm::normalize(glm::cross(_front, _up)) * delta;
	}
}
void MountainTunnel::Camera::SetProjection(const MountainTunnel::Window& window)
{
	glm::vec2 framebufferSize = window.GetFramebufferSize();
	if (framebufferSize.x > 0.0f || framebufferSize.y > 0.0f)
	{
		_projection = glm::perspective(glm::radians(_fov), framebufferSize.x / framebufferSize.y, _near, _far);
	}
}
void MountainTunnel::Camera::SetView()
{
	_view = glm::lookAt(_position, _position + _front, _up);
}
const glm::mat4& MountainTunnel::Camera::GetProjection() const
{
	return _projection;
}
const glm::mat4& MountainTunnel::Camera::GetView() const
{
	return _view;
}
glm::vec3 MountainTunnel::Camera::GetPosition() const
{
	return _position;
}
glm::vec3 MountainTunnel::Camera::GetFront() const
{
	return _front;
}