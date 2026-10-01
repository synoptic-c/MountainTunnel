#include"Timer.hpp"
MountainTunnel::Timer::Timer() : _delta{}, _last{}
{
	_last = std::chrono::steady_clock::now();
}
void MountainTunnel::Timer::Update()
{
	std::chrono::steady_clock::time_point current = std::chrono::steady_clock::now();
	_delta = current - _last;
	_last = current;
}
float MountainTunnel::Timer::GetDelta() const
{
	return _delta.count();
}