#pragma once
#include "Time.h"

namespace Ane
{
class Timer
{
public:
	Timer();
	virtual ~Timer();

public:
	void										SetTimer(Ane::Time* pTime, unsigned int Interval);
	void										KillTimer(Ane::Time* pTime);
	void										SetAlarm(Ane::Time* pTime, unsigned int Interval);

	virtual void								OnTimer(Ane::Time* pTime)				{}
	virtual void								OnAlarm(Ane::Time* pTime)				{}
};
}//namespace Ane