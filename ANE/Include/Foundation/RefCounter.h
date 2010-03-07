#pragma once
#include "LockFreeCounter.h"

namespace Ane
{
class RefCounter
{
public:
	RefCounter();
	virtual ~RefCounter();

public:
	int 										GetRef();
	void										InitRef();
	void										AddRef();
	void										Release();

protected:
	virtual void								OnRelease();

private:
	LockFreeCounter								m_RefCounter;
};

RefCounter::RefCounter()
:m_RefCounter(0)
{

}

RefCounter::~RefCounter()
{

}

inline int RefCounter::GetRef()
{
	return this->m_RefCounter;
}

inline void RefCounter::InitRef()
{
	this->m_RefCounter = 0;
}

inline void RefCounter::AddRef()
{
	++this->m_RefCounter;
}

inline void RefCounter::Release()
{
	--this->m_RefCounter;
	if(this->m_RefCounter == 0)
		this->OnRelease();
}

inline void RefCounter::OnRelease()
{
	delete this;
}

}//namespace Ane