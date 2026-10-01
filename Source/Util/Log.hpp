#pragma once
#include<string_view>
#include<cstdio>
#define FILE_LINE __FILE__, __LINE__
namespace MountainTunnel
{
	class Log
	{
	private:

	public:
		static void Error(std::string_view file, int line, std::string_view message);
		static void ErrorFile(std::string_view file, int line, std::string_view path, std::string_view message = "Failed to open file");
	};
}