#include "LockedList.h"
#include "Node.h"

namespace Ane
{
LockedList::LockedList() 
	:m_pHead(NULL), m_pTail(NULL), m_Count(0)
{
	m_pHead = new Node;
	m_pTail = new Node;
	m_pHead->m_pNext = m_pTail;
	m_pTail->m_pPrev = m_pHead;
}

LockedList::~LockedList()
{
	this->Clear();
	delete m_pHead;
	delete m_pTail;
	m_pHead = NULL;
	m_pTail = NULL;
}

void LockedList::PushBack( Node* pNode )
{
	this->PushNext(m_pTail->m_pPrev, pNode);
}

void LockedList::PushFront( Node* pNode )
{
	this->PushNext(m_pHead, pNode);
}

Node* LockedList::PopBack()
{
	Node* pNode = m_pTail->m_pPrev;
	this->PopAt(pNode);
	return pNode;
}

Node* LockedList::PopFront()
{
	Node* pNode = m_pHead->m_pNext;
	this->PopAt(pNode);
	return pNode;
}

void LockedList::PushNext( Node* pPrev, Node* pNode )
{
	Node* pNext = pPrev->m_pNext;

	pPrev->m_pNext = pNode;
	pNode->m_pPrev = pPrev;

	pNext->m_pPrev = pNode;
	pNode->m_pNext = pNext;

	pNode->m_CurrentList = this;

	++m_Count;
}

void LockedList::PopAt( Node* pNode )
{
	if(this->IsEmpty())
		return;

	Node* pPrev = pNode->m_pPrev;
	Node* pNext = pNode->m_pNext;

	pPrev->m_pNext = pNext;
	pNext->m_pPrev = pPrev;

	pNode->ReSet();

	--m_Count;
}

unsigned int LockedList::Size()
{
	return m_Count;
}

void LockedList::Clear()
{
//	bool bRet = IsEmpty();
	while(!this->IsEmpty())
	{
		this->PopFront();
	}
}

bool LockedList::IsEmpty()
{
	return (NULL == m_pHead->m_pNext->m_pNext);
}


}//namespace AneUtil