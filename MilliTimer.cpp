/*
 * MilliTimer.cpp
 *
 *  Created on: Jun 4, 2019
 *      Author: Martin Collins
 */

#include "MilliTimer.h"

MilliTimer::MilliTimer(unsigned long microseconds, bool enable = false)
{
	_microseconds = microseconds;
	_enable = enable;
	_running = false;
	_timer_start_timestamp = 0;
}

void MilliTimer::enable()
{
	_enable = true;
}

void MilliTimer::disable()
{
	_enable = false;
}

void MilliTimer::start()
{
	if(_enable == true && _running == false)
	{
		_timer_start_timestamp = millis();
		_running = true;
	}
}

void MilliTimer::stop()
{
	if(_enable == true && _running == true)
	{
		_timer_start_timestamp = 0;
		_running = false;
	}
}

void MilliTimer::restart()
{
	if(_enable == true && _running == true)
	{
		_timer_start_timestamp = millis();
	}
}

bool MilliTimer::isEnabled()
{
	return _enable;
}

bool MilliTimer::isRunning()
{
	return _running;
}

bool MilliTimer::isElapsed()
{
	if(((millis() - _timer_start_timestamp) >= _microseconds) && _running == true)
	{
		return (true);
	}
	return (false);
}

void MilliTimer::setDuration(unsigned long microseconds)
{
		_microseconds = microseconds;
}

unsigned long MilliTimer::elapsedDuration()
{
	return (millis() - _timer_start_timestamp);
}

unsigned long MilliTimer::getDuration()
{
	return _microseconds;
}
