#pragma once
#include<memory>
#include<string_view>
#include<fstream>
#include<vector>
#include<glm/ext/matrix_float4x4.hpp>
#include<glm/ext/vector_float3.hpp>
#include<glm/trigonometric.hpp>
#include<nlohmann/json.hpp>
#include"Platform/Context.hpp"
#include"Platform/Window.hpp"
#include"Util/Timer.hpp"
#include"Platform/Input.hpp"
#include"Render/Camera.hpp"
#include"Framework/Map.hpp"
#include"Framework/Object.hpp"
#include"Render/Shader.hpp"
#include"Util/Log.hpp"
namespace MountainTunnel
{
	class Application
	{
	private:
		std::unique_ptr<MountainTunnel::Context> _context;
		std::unique_ptr<MountainTunnel::Window> _window;
		MountainTunnel::Timer _timer;
		MountainTunnel::Input _input;
		MountainTunnel::Camera _camera;
		std::unique_ptr<MountainTunnel::Object> _object;
		std::unique_ptr<MountainTunnel::Shader> _shader;
	public:
		Application();
		void Initialize();
		void Run();
		void Update();
		void Render();
	};
}