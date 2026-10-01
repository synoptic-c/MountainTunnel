#include"Shader.hpp"
void MountainTunnel::Shader::LoadShader(std::string_view path, std::string& source)
{
	std::ifstream file{ std::string(path) };
	if (!file)
	{
		MountainTunnel::Log::ErrorFile(FILE_LINE, path, "Failed to open shader");
		return;
	}
	std::stringstream buffer;
	buffer << file.rdbuf();
	source = buffer.str();
}
unsigned int MountainTunnel::Shader::CreateShader(std::string_view source, unsigned int type)
{
	unsigned int shader = glCreateShader(type);
	const char* string = source.data();
	glShaderSource(shader, 1, &string, NULL);
	glCompileShader(shader);
	int params;
	glGetShaderiv(shader, GL_COMPILE_STATUS, &params);
	if (!params)
	{
		int length;
		glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &length);
		std::string infoLog(length, '\n');
		glGetShaderInfoLog(shader, length, NULL, infoLog.data());
		MountainTunnel::Log::Error(FILE_LINE, infoLog);
		glDeleteShader(shader);
		return {};
	}
	return shader;
}
MountainTunnel::Shader::Shader(std::string_view vertexPath, std::string_view fragmentPath) : _program{}
{
	std::string vertexSource;
	std::string fragmentSource;
	MountainTunnel::Shader::LoadShader(vertexPath, vertexSource);
	MountainTunnel::Shader::LoadShader(fragmentPath, fragmentSource);
	unsigned int vertexShader = MountainTunnel::Shader::CreateShader(vertexSource, GL_VERTEX_SHADER);
	unsigned int fragmentShader = MountainTunnel::Shader::CreateShader(fragmentSource, GL_FRAGMENT_SHADER);
	if (!vertexShader || !fragmentShader)
	{
		return;
	}
	_program = glCreateProgram();
	glAttachShader(_program, vertexShader);
	glAttachShader(_program, fragmentShader);
	glLinkProgram(_program);
	glDeleteShader(vertexShader);
	glDeleteShader(fragmentShader);
	int params;
	glGetProgramiv(_program, GL_LINK_STATUS, &params);
	if (!params)
	{
		int length;
		glGetProgramiv(_program, GL_INFO_LOG_LENGTH, &length);
		std::string infoLog(length, '\n');
		glGetProgramInfoLog(_program, length, NULL, infoLog.data());
		MountainTunnel::Log::Error(FILE_LINE, infoLog);
		glDeleteProgram(_program);
		_program = {};
		return;
	}
}
MountainTunnel::Shader::~Shader()
{
	if (_program)
	{
		glDeleteProgram(_program);
		_program = {};
	}
}
MountainTunnel::Shader::Shader(MountainTunnel::Shader&& other) noexcept
{
	_program = other._program;
	other._program = {};
}
MountainTunnel::Shader& MountainTunnel::Shader::operator=(MountainTunnel::Shader&& other) noexcept
{
	if (this != &other)
	{
		if (_program)
		{
			glDeleteProgram(_program);
		}
		_program = other._program;
		other._program = {};
	}
	return *this;
}
void MountainTunnel::Shader::Use() const
{
	if (_program)
	{
		glUseProgram(_program);
	}
}
void MountainTunnel::Shader::SetMat4(std::string_view name, const glm::mat4& value) const
{
	if (_program)
	{
		int location = glGetUniformLocation(_program, std::string(name).c_str());
		glProgramUniformMatrix4fv(_program, location, 1, GL_FALSE, glm::value_ptr(value));
	}
}
void MountainTunnel::Shader::SetVec3(std::string_view name, glm::vec3 value) const
{
	if (_program)
	{
		int location = glGetUniformLocation(_program, std::string(name).c_str());
		glProgramUniform3f(_program, location, value.x, value.y, value.z);
	}
}
void MountainTunnel::Shader::SetFloat(std::string_view name, float value) const
{
	if (_program)
	{
		int location = glGetUniformLocation(_program, std::string(name).c_str());
		glProgramUniform1f(_program, location, value);
	}
}
void MountainTunnel::Shader::SetUInt(std::string_view name, unsigned int value) const
{
	if (_program)
	{
		int location = glGetUniformLocation(_program, std::string(name).c_str());
		glProgramUniform1ui(_program, location, value);
	}
}