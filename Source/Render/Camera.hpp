#pragma once
#include<glm/ext/vector_float3.hpp>
#include<glm/ext/vector_float2.hpp>
#include<glm/ext/matrix_float4x4.hpp>
#include<glm/trigonometric.hpp>
#include<glm/geometric.hpp>
#include<glm/ext/matrix_clip_space.hpp>
#include<glm/ext/matrix_transform.hpp>
#include"Platform/Window.hpp"
#include"Platform/Input.hpp"
#include"Util/Timer.hpp"
namespace MountainTunnel
{
	class Camera
	{
	private:
		glm::vec3 _position;
		glm::vec3 _up;
		glm::vec3 _front;
		glm::vec2 _last;
		float _yaw;
		float _pitch;
		float _pitchLimit;
		float _fov;
		float _near;
		float _far;
		glm::mat4 _projection;
		glm::mat4 _view;
	public:
		Camera();
		void Update(const MountainTunnel::Window& window, MountainTunnel::Input input, MountainTunnel::Timer timer);
		void ProcessMouse(const MountainTunnel::Window& window);
		void ProcessMove(const MountainTunnel::Window& window, MountainTunnel::Input input, MountainTunnel::Timer timer);
		void SetProjection(const MountainTunnel::Window& window);
		void SetView();
		const glm::mat4& GetProjection() const;
		const glm::mat4& GetView() const;
		glm::vec3 GetPosition() const;
		glm::vec3 GetFront() const;
	};
}