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
	// �����ð�
	unsigned int								m_Interval;
	// ���������� ȣ��� �ð�
	unsigned int								m_LastTime;
	// ����ũ ���̵�
	UniqueID									m_UniqueID;
};
}//namespace Ane