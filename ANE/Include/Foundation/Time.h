#pragma once
#include "Common/CommonHeader.h"

namespace Ane
{
class Time
{
public:
	Time():m_Interval(0), m_LastTime(0), m_UniqueID(0)							{	}
	virtual ~Time()																{	}

	BOOL										operator == (Time* pTime)		{	return m_UniqueID == pTime->m_UniqueID;	}
	BOOL										operator == (Time& pTime)		{	return m_UniqueID == pTime.m_UniqueID;	}

private:
	friend class TimeManager;
	friend class Timer;
	unsigned int								m_Interval;
	unsigned int								m_LastTime;
	unsigned int								m_UniqueID;
};
}//namespace Ane