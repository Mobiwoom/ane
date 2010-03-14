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
	void										Initialize()			{	InitializeCriticalSection(&m_CriticalSection);	}
	void										Enter()					{	EnterCriticalSection(&m_CriticalSection);	}
	void										Leave()					{	LeaveCriticalSection(&m_CriticalSection);	}

private:
	CRITICAL_SECTION							m_CriticalSection;
};
}//namespace Ane