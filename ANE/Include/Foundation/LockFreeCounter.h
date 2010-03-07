#pragma once
#include "Common/CommonHeader.h"

namespace Ane
{
class LockFreeCounter
{
public:
	LockFreeCounter();
	LockFreeCounter(long Num);
	~LockFreeCounter();

public:
	long										Increment();
	long										Decrement();
	long										Exchange(long Num);
	long										ExchangeAdd(long Num);
	long										ExchangeSub(long Num);
	long										GetCount();

public:
	long										operator++();
	long										operator++(int);
	long										operator--();
	long										operator--(int);
	void										operator+=(long Num);
	void										operator-=(long Num);
	void										operator=(long Num);
												operator volatile long() const		{return m_Count;}

private:
	volatile long								m_Count;
};

LockFreeCounter::LockFreeCounter()
{
	this->Exchange(0);
}

LockFreeCounter::LockFreeCounter(long Num)
{
	this->Exchange(Num);
}

LockFreeCounter::~LockFreeCounter()
{
	this->Exchange(0);
}

inline long LockFreeCounter::Increment()
{
	return InterlockedIncrement(&m_Count);
}

inline long LockFreeCounter::Decrement()
{
	return InterlockedDecrement(&m_Count);
}

inline long LockFreeCounter::Exchange(long Num)
{
	return InterlockedExchange(&m_Count, Num);
}

inline long LockFreeCounter::ExchangeAdd(long Num)
{
	return InterlockedExchangeAdd(&m_Count, Num);
}

inline long LockFreeCounter::ExchangeSub(long Num)
{
	return InterlockedExchangeAdd(&m_Count, -Num);
}

inline long LockFreeCounter::GetCount()
{
	return m_Count;
}

inline long LockFreeCounter::operator ++()
{
	return this->Increment();
}

inline long LockFreeCounter::operator --()
{
	return this->Decrement();
}

inline long LockFreeCounter::operator ++(int)
{
	return this->Increment() - 1;
}

inline long LockFreeCounter::operator --(int)
{
	return this->Decrement() + 1;
}

inline void	LockFreeCounter::operator +=(long Num)
{
	this->ExchangeAdd(Num);
}

inline void	LockFreeCounter::operator -=(long Num)
{
	this->ExchangeSub(Num);
}

inline void LockFreeCounter::operator =(long Num)
{
	this->Exchange(Num);
}



};//namespace Ane