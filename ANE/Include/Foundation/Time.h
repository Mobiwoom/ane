#pragma once
#include "Common/CommonHeader.h"

namespace Ane
{
class Time
{
	friend class TimeManager;
	friend class Timer;
public:
	Time():m_Interval(0), m_LastTime(0), m_UniqueID(0)							{	}
	virtual ~Time()																{	}

	BOOL										operator == (Time* pTime)		{	return m_UniqueID == pTime->m_UniqueID;	}
	BOOL										operator == (Time& pTime)		{	return m_UniqueID == pTime.m_UniqueID;	}

private:
	// 지연시간
	unsigned int								m_Interval;
	// 마지막으로 호출된 시간
	unsigned int								m_LastTime;
	// 유니크 아이디
	UniqueID									m_UniqueID;
};
}//namespace Ane