#pragma once
#include "Common/CommonHeader.h"

namespace Ane
{
class LockFreeCounter
{
public:
	LockFreeCounter()							{this->Exchange(0);}
	LockFreeCounter(long Num)					{this->Exchange(Num);}
	~LockFreeCounter()							{this->Exchange(0);}

public:
	long										Increment()							{	return InterlockedIncrement(&m_Count);	}
	long										Decrement()							{	return InterlockedDecrement(&m_Count);	}
	long										Exchange(long Num)					{	return InterlockedExchange(&m_Count, Num);	}
	long										ExchangeAdd(long Num)				{	return InterlockedExchangeAdd(&m_Count, Num);	}
	long										ExchangeSub(long Num)				{	return InterlockedExchangeAdd(&m_Count, -Num);	}
	long										GetCount()							{	return m_Count;	}

public:
	long										operator++()						{	return this->Increment();	}
	long										operator++(int)						{	return this->Increment() - 1;	}
	long										operator--()						{	return this->Decrement();	}
	long										operator--(int)						{	return this->Decrement() + 1;	}
	void										operator+=(long Num)				{	this->ExchangeAdd(Num);	}
	void										operator-=(long Num)				{	this->ExchangeSub(Num);	}
	void										operator=(long Num)					{	this->Exchange(Num);	}
												operator volatile long() const		{return m_Count;}

private:
	volatile long								m_Count;
};
};//namespace Ane