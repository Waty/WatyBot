#pragma once

#include "noncopyable.h"
#include <chrono>

using namespace std::chrono;

template<typename T>
class StopWatch
{
public:
	StopWatch(T tDelay)
	{
		m_timePoint = high_resolution_clock::now();
		m_tDelay = tDelay;
	}

	StopWatch()
	{
		m_timePoint = high_resolution_clock::now();
		m_tDelay = T(0);
	}

	void SetDelay(T tDelay)
	{
		m_tDelay = tDelay;
	}
	void Start()
	{
		m_timePoint = high_resolution_clock::now();
	}

	bool IsOver()
	{
		high_resolution_clock::time_point timePoint = high_resolution_clock::now();
		T dur = duration_cast<T>(timePoint - m_timePoint);
		return dur.count() >= m_tDelay.count();
	}

private:
	T m_tDelay;
	high_resolution_clock::time_point m_timePoint;
};
