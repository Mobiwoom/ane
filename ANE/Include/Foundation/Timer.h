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
	// Timer 등록 (Interval 간격으로 주기적으로 OnTimer() 호출) 단위 : millisecond
	void										SetTimer(Ane::Time* pTime, unsigned int Interval);
	// Timer 등록 해제
	void										KillTimer(Ane::Time* pTime);
	// Alarm 등록 (Interval 시간 만큼 지난 후 한번만 OnAlarm() 호출) 단위 : millisecond
	void										SetAlarm(Ane::Time* pTime, unsigned int Interval);

public:
	virtual void								OnTimer(Ane::Time* pTime)				{UNREFERENCED_PARAMETER(pTime);}
	virtual void								OnAlarm(Ane::Time* pTime)				{UNREFERENCED_PARAMETER(pTime);}
};
}//namespace Ane