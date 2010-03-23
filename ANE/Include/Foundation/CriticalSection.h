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
	// CriticalSection �ʱ�ȭ
	void										Initialize()			{	InitializeCriticalSection(&m_CriticalSection);	}
	// CriticalSection ����
	void										Enter()					{	EnterCriticalSection(&m_CriticalSection);	}
	// CriticalSection ����
	void										Leave()					{	LeaveCriticalSection(&m_CriticalSection);	}

private:
	CRITICAL_SECTION							m_CriticalSection;
};
}//namespace Ane