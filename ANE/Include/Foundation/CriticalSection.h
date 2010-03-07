#pragma once
#include "Common/CommonHeader.h"

namespace Ane
{
class CriticalSection
{
public:
	CriticalSection();
	~CriticalSection();

public:
	void										Initialize();
	void										Enter();
	void										Leave();

private:
	CRITICAL_SECTION							m_CriticalSection;
};

CriticalSection::CriticalSection()
{
	this->Initialize();
}

CriticalSection::~CriticalSection()
{

}

inline void CriticalSection::Initialize()
{
	InitializeCriticalSection(&m_CriticalSection);
}

inline void CriticalSection::Enter()
{
	EnterCriticalSection(&m_CriticalSection);
}

inline void CriticalSection::Leave()
{
	LeaveCriticalSection(&m_CriticalSection);
}

}//namespace Ane