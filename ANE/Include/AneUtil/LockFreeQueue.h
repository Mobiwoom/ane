#pragma once
#include "LockFreeSelfStack.h"

namespace AneUtil
{
template <typename Type>
class LockFreeQueue
{
	class Node
	{
	public:
		Type	m_tData;
		Node*	m_pNext;
	};
public:
	LockFreeQueue();
	~LockFreeQueue();

public:
	void										Push(const Type& tData);
	Type										Pop();
	void										Clear();

private:
	Node*										Alloc();

private:
	static LockFreeSelfStack<Node*>				m_NodePool;
	volatile PVOID								m_pHead;
	volatile PVOID								m_pTail;
};

template <typename Type>
LockFreeSelfStack<typename LockFreeQueue<Type>::Node*> LockFreeQueue<Type>::m_NodePool;

template <typename Type>
LockFreeQueue<Type>::LockFreeQueue()
:m_pHead(NULL), m_pTail(NULL)
{
	Node* pNode		= this->Alloc();
	pNode->m_pNext	= 0;
	m_pHead			= pNode;
	m_pTail			= pNode;
}

template <typename Type>
LockFreeQueue<Type>::~LockFreeQueue()
{
	
}

template <typename Type>
typename LockFreeQueue<Type>::Node* LockFreeQueue<Type>::Alloc()
{
	Node* pNode = m_NodePool.Pop();

	if(0 == pNode)
		pNode = new Node;
	return pNode;
}

template <typename Type>
void LockFreeQueue<Type>::Push(const Type& tData)
{
	Node* pNode = this->Alloc();

	pNode->m_tData = tData;
	pNode->m_pNext = 0;

	Node* pTemp;

	do
	{
		pTemp = (Node*)m_pTail;
	}while(InterlockedCompareExchangePointer(&m_pTail, pNode, pTemp)!=pTemp);
	pTemp->m_pNext = pNode;
}

template <typename Type>
Type LockFreeQueue<Type>::Pop()
{
	Node* pHead;
	Node* pNext;

	do 
	{
		pHead = (Node*)m_pHead;
		pNext = (Node*)pHead->m_pNext;

		if(pNext==0)
			return	0;

	} while (InterlockedCompareExchangePointer(&m_pHead, pNext, pHead)!=pHead);
	m_NodePool.Push(pHead);

	return	pNext->m_tData;
}

template <typename Type>
void LockFreeQueue<Type>::Clear()
{
	while(1)
	{
		
		Node* pHead;
		Node* pNext;

		do
		{
			pHead = (Node*)m_pHead;
			pNext = (Node*)pHead->m_pNext;

			if(pNext==0)
				return;

		} while(InterlockedCompareExchangePointer(&m_pHead, pNext, pHead)!=pHead);

		m_NodePool.Push(pHead);

		pNext->m_tData.~Type();
	}
}
}//namespace Mogi