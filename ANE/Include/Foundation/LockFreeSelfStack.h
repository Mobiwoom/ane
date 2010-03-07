#pragma once
#include "CommonHeader.h"

#pragma intrinsic(_InterlockedCompareExchange64)

namespace Ane
{
template <typename Type>
class LockFreeSelfStack
{
	union StackHead
	{
		__int64			alligned;
		struct
		{
			Type			pHead;
			unsigned short	wDepth;
			unsigned short	wSequence;
		}partial;
	};

public:
	LockFreeSelfStack()							{Clear();}
	~LockFreeSelfStack()						{}

public:
	int											Size()						{return	m_Head.partial.wDepth;}
	void										Clear();
	void										Push(const Type& tData);
	Type										Pop();
	Type										PopAll();

private:
	volatile StackHead							m_Head;
};

template <typename Type>
void LockFreeSelfStack<Type>::Clear()
{
	this->PopAll();
}

template <typename Type>
void LockFreeSelfStack<Type>::Push(const Type& tData)
{
	StackHead Head;
	StackHead NewHead;

	do 
	{
		Head.alligned				= m_Head.alligned;
		tData->m_pNext				= m_Head.partial.pHead;
		NewHead.partial.pHead		= tData;
		NewHead.partial.wDepth		= Head.partial.wDepth+1;
		NewHead.partial.wSequence	= Head.partial.wSequence+1;
	} while (_InterlockedCompareExchange64(&m_Head.alligned, NewHead.alligned, Head.alligned)!=Head.alligned);
}

template <typename Type>
Type LockFreeSelfStack<Type>::Pop()
{
	StackHead Head;
	StackHead NewHead;

	do 
	{
		Head.alligned				= m_Head.alligned;

		if(Head.partial.pHead==0)
			return	0;

		NewHead.partial.pHead		 = Head.partial.pHead->m_pNext;
		NewHead.partial.wDepth		 = Head.partial.wDepth-1;
		NewHead.partial.wSequence	 = Head.partial.wSequence+1;
	} while (_InterlockedCompareExchange64(&m_Head.alligned, NewHead.alligned, Head.alligned)!=Head.alligned);
	return Head.partial.pHead;
}

template <typename Type>
Type LockFreeSelfStack<Type>::PopAll()
{
	StackHead Head;
	StackHead NewHead;

	do
	{
		Head.alligned			= m_Head.alligned;
		NewHead.partial.pHead		= 0;
		NewHead.partial.wDepth		= 0;
		NewHead.partial.wSequence	= Head.partial.wSequence+1;

	} while(_InterlockedCompareExchange64(&m_Head.alligned, NewHead.alligned, Head.alligned)!=Head.alligned);

	return	Head.partial.pHead;
}
}//namespace Mogi
