#pragma once
#include "LockFreeCounter.h"

namespace Ane
{
class RefCounter
{
public:
	RefCounter():m_RefCounter(0)				{	}
	virtual ~RefCounter()						{	}

public:
	int 										GetRef()					{	return this->m_RefCounter;	}
	void										InitRef()					{	this->m_RefCounter = 0;}
	void										AddRef()					{	++this->m_RefCounter;}
	void										Release()					{	--this->m_RefCounter;	if(this->m_RefCounter == 0)	this->OnRelease();	}

protected:
	virtual void								OnRelease()					{	delete this;	}

private:
	Ane::LockFreeCounter						m_RefCounter;
};
}//namespace Ane