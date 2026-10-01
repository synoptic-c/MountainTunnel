#include"Application.hpp"
MountainTunnel::Application::Application()
{
	Initialize();
}
void MountainTunnel::Application::Initialize()
{
	_context = std::make_unique<MountainTunnel::Context>(4, 5);
	_window = std::make_unique<MountainTunnel::Window>(640, 360, "MountainTunnel");
	_context->LoadGLLoader();
	std::string_view path = "Assets/Meshes/Quad.json";
	std::ifstream file{ std::string(path)};
	if (!file)
	{
		MountainTunnel::Log::ErrorFile(FILE_LINE, path);
	}
	nlohmann::json json(nlohmann::json::parse(file));
	std::vector<MountainTunnel::Vertex> vertices(json["vertices"].get<std::vector<MountainTunnel::Vertex>>());
	std::vector<unsigned int> indices(json["indices"].get<std::vector<unsigned int>>());
	MountainTunnel::Map map("Assets/Maps/Road.json", vertices, indices);
	_object = std::make_unique<MountainTunnel::Object>(map.GetVerticesObject(), map.GetIndicesObject(), map.GetTexturesPathObject(), map.GetPositionsObject(), map.GetScalesObject());
	_shader = std::make_unique<MountainTunnel::Shader>("Assets/Shaders/Phong.vert", "Assets/Shaders/Phong.frag");
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_CULL_FACE);
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
}
void MountainTunnel::Application::Run()
{
	while (!_window->WindowShouldClose())
	{
		Update();
		Render();
	}
}
void MountainTunnel::Application::Update()
{
	_window->PollEvents();
	_timer.Update();
	_input.Update(*_window);
	_camera.Update(*_window, _input, _timer);
}
void MountainTunnel::Application::Render()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	_shader->Use();
	_shader->SetMat4("u_projection", _camera.GetProjection());
	_shader->SetMat4("u_view", _camera.GetView());
	_shader->SetMat4("u_model", glm::mat4(1.0f));
	_shader->SetVec3("u_viewPosition", _camera.GetPosition());
	_shader->SetFloat("u_shininess", 32.0f);
	_shader->SetVec3("u_orientLight.direction", glm::vec3(-0.2f, -1.0f, -0.2f));
	_shader->SetVec3("u_orientLight.ambient", glm::vec3(0.05f, 0.05f, 0.05f));
	_shader->SetVec3("u_orientLight.diffuse", glm::vec3(0.4f, 0.4f, 0.4f));
	_shader->SetVec3("u_orientLight.specular", glm::vec3(0.5f, 0.5f, 0.5f));
	_shader->SetVec3("u_pointLight[0].position", glm::vec3(1.0f, 0.2f, 2.0f));
	_shader->SetVec3("u_pointLight[0].ambient", glm::vec3(0.05f, 0.05f, 0.05f));
	_shader->SetVec3("u_pointLight[0].diffuse", glm::vec3(0.8f, 0.8f, 0.8f));
	_shader->SetVec3("u_pointLight[0].specular", glm::vec3(1.0f, 1.0f, 1.0f));
	_shader->SetFloat("u_pointLight[0].constant", 1.0f);
	_shader->SetFloat("u_pointLight[0].linear", 0.09f);
	_shader->SetFloat("u_pointLight[0].quadratic", 0.032f);
	_shader->SetVec3("u_pointLight[1].position", glm::vec3(2.0f, 0.2f, 2.0f));
	_shader->SetVec3("u_pointLight[1].ambient", glm::vec3(0.05f, 0.05f, 0.05f));
	_shader->SetVec3("u_pointLight[1].diffuse", glm::vec3(0.8f, 0.8f, 0.8f));
	_shader->SetVec3("u_pointLight[1].specular", glm::vec3(1.0f, 1.0f, 1.0f));
	_shader->SetFloat("u_pointLight[1].constant", 1.0f);
	_shader->SetFloat("u_pointLight[1].linear", 0.09f);
	_shader->SetFloat("u_pointLight[1].quadratic", 0.032f);
	_shader->SetVec3("u_spotLight.position", _camera.GetPosition());
	_shader->SetVec3("u_spotLight.direction", _camera.GetFront());
	_shader->SetVec3("u_spotLight.ambient", glm::vec3(0.0f, 0.0f, 0.0f));
	_shader->SetVec3("u_spotLight.diffuse", glm::vec3(1.0f, 1.0f, 1.0f));
	_shader->SetVec3("u_spotLight.specular", glm::vec3(1.0f, 1.0f, 1.0f));
	_shader->SetFloat("u_spotLight.constant", 1.0f);
	_shader->SetFloat("u_spotLight.linear", 0.09f);
	_shader->SetFloat("u_spotLight.quadratic", 0.32f);
	_shader->SetFloat("u_spotLight.cutOff", glm::cos(glm::radians(30.0f)));
	_shader->SetFloat("u_spotLight.outerCutOff", glm::cos(glm::radians(40.0f)));
	_object->Render();
	_window->SwapBuffers();
}