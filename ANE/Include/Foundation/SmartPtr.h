#pragma once
#include "Common/CommonHeader.h"
#include "Foundation/LockFreeCounter.h"

// 이걸 만들어야 되나 말아야 되나...;ㅁ;

namespace Ane
{
template <typename Type>
class Smart_Ptr
{
public:
	Smart_Ptr();
	Smart_Ptr(Type* pType);
	~Smart_Ptr();

	LockFreeCounter*							Alloc();


private:
	Type*										m_pRef;
	LockFreeCounter*							m_pCount;
	static LockFreeQueue<LockFreeCounter*>		m_CountPool;
};

template <typename Type>
LockFreeQueue<LockFreeCounter*> Smart_Ptr<Type>::m_CountPool;

template <typename Type>
Smart_Ptr<Type>::Smart_Ptr()
:m_pCount(NULL), m_pRef(NULL)
{

}

template <typename Type>
Smart_Ptr<Type>::Smart_Ptr(Type* pType)
:m_pCount(NULL), m_pRef(pType)
{
	m_pCount = this->Alloc();
}

template <typename Type>
Smart_Ptr<Type>::~Smart_Ptr()
{

}

template <typename Type>
LockFreeCounter* Smart_Ptr<Type>::Alloc()
{
	LockFreeCounter* pCount = m_CountPool.Pop();

	if(NULL == pCount)
		pCount = new LockFreeCounter(1);

	return pCount;
}


}//namespace Ane