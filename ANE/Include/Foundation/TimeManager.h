#pragma once
#include "Singleton.h"
#include "CriticalSection.h"

namespace Ane
{
class Time;
class Timer;
class TimeManager
	: public Ane::Singleton<TimeManager>
	, public WSAOVERLAPPED
{
public:
	TimeManager();
	virtual ~TimeManager();

public:
	void										Start();
	void										Stop();
	void										Complete();

	void										AttachTimer(Ane::Time* pTime, Ane::Timer* pTimer);
	void										DetachTimer(Ane::Time* pTime);
	void										AttachAlarm(Ane::Time* pTime, Ane::Timer* pTimer);



private:
	BOOL										m_isStart;
	Ane::CriticalSection						m_Lock;

};

}//namespace Ane