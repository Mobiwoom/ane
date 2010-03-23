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
	// Timer ��� (Interval �������� �ֱ������� OnTimer() ȣ��) ���� : millisecond
	void										SetTimer(Ane::Time* pTime, unsigned int Interval);
	// Timer ��� ����
	void										KillTimer(Ane::Time* pTime);
	// Alarm ��� (Interval �ð� ��ŭ ���� �� �ѹ��� OnAlarm() ȣ��) ���� : millisecond
	void										SetAlarm(Ane::Time* pTime, unsigned int Interval);

public:
	virtual void								OnTimer(Ane::Time* pTime)				{UNREFERENCED_PARAMETER(pTime);}
	virtual void								OnAlarm(Ane::Time* pTime)				{UNREFERENCED_PARAMETER(pTime);}
};
}//namespace Ane