#pragma once
#include<chrono>
namespace MountainTunnel
{
	class Timer
	{
	private:
		std::chrono::duration<float> _delta;
		std::chrono::steady_clock::time_point _last;
	public:
		Timer();
		void Update();
		float GetDelta() const;
	};
}