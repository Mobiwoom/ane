#pragma once
#include "Common/CommonHeader.h"
#include "LockFreeCounter.h"

namespace Ane
{
class RefCounter
{
public:
	RefCounter():m_RefCounter(0)				{	}
	virtual ~RefCounter()						{	}

public:
	// 참조 카운터 얻어오기
	int 										GetRef()					{	return this->m_RefCounter;	}
	// 참조 카운터 초기화
	void										InitRef()					{	this->m_RefCounter = 0;		}
	// 참조 카운터 증가
	void										AddRef()					{	++this->m_RefCounter;		}
	// 참조 카운터 감소 후 참조 카운터가 0이면 OnRelease() 호출
	void										Release()					{	--this->m_RefCounter;	if(this->m_RefCounter == 0)	this->OnRelease();	}

protected:
	// 상속 받은 객체에서 재정의 하지 않으면 객체를 지움
	virtual void								OnRelease()					{	ANE_DELETE(this);	}

private:
	Ane::LockFreeCounter						m_RefCounter;
};
}//namespace Ane