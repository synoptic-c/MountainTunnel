#include"Log.hpp"
void MountainTunnel::Log::Error(std::string_view file, int line, std::string_view message)
{
	std::printf("File:%s\nLine:%d\nMessage:%s\n",
		file.data(),
		line,
		message.data()
	);
}
void MountainTunnel::Log::ErrorFile(std::string_view file, int line, std::string_view path, std::string_view message)
{
	MountainTunnel::Log::Error(file, line, message);
	std::printf("Path:%s\n",
		path.data()
	);
}