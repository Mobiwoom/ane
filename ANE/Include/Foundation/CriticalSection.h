#pragma once
#include "Common/CommonHeader.h"

namespace Ane
{
class CriticalSection
{
public:
	CriticalSection()							{	this->Initialize();	}
	~CriticalSection()							{	}

public:
	// CriticalSection 초기화
	void										Initialize()			{	InitializeCriticalSection(&m_CriticalSection);	}
	// CriticalSection 진입
	void										Enter()					{	EnterCriticalSection(&m_CriticalSection);	}
	// CriticalSection 해제
	void										Leave()					{	LeaveCriticalSection(&m_CriticalSection);	}

private:
	CRITICAL_SECTION							m_CriticalSection;
};
}//namespace Ane