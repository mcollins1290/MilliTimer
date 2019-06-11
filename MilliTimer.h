/*
 * MilliTimer.h
 *
 *  Created on: Jun 4, 2019
 *      Author: Martin Collins
 */

#ifndef MILLITIMER_H_
#define MILLITIMER_H_

#include "Arduino.h"

class MilliTimer
{
public:
	MilliTimer(unsigned long microseconds, bool enable);
	void enable();
	void disable();
	void start();
	void stop();
	void restart();
	void setDuration(unsigned long microseconds);
	bool isEnabled();
	bool isRunning();
	bool isElapsed();
	unsigned long elapsedDuration();
	unsigned long getDuration();
private:
	unsigned long _microseconds;
	bool _enable;
	bool _running;
	unsigned long _timer_start_timestamp;
};

#endif /* MILLITIMER_H_ */

#pragma once
