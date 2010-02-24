#include "List.h"
#include "Node.h"

namespace AneUtil
{
List::List() 
	:m_pHead(0), m_pTail(0), m_Count(0)
{
	m_pHead = new Node;
	m_pTail = new Node;
	m_pHead->m_pNext = m_pTail;
	m_pTail->m_pPrev = m_pHead;
}

List::~List()
{
	this->Clear();
	delete m_pHead;
	delete m_pTail;
	m_pHead = 0;
	m_pTail = 0;
}

void List::PushBack( Node* pNode )
{
	this->PushNext(m_pTail->m_pPrev, pNode);
}

void List::PushFront( Node* pNode )
{
	this->PushNext(m_pHead, pNode);
}

Node* List::PopBack()
{
	Node* pNode = m_pTail->m_pPrev;
	this->PopAt(pNode);
	return pNode;
}

Node* List::PopFront()
{
	Node* pNode = m_pHead->m_pNext;
	this->PopAt(pNode);
	return pNode;
}

void List::PushNext( Node* pPrev, Node* pNode )
{
	Node* pNext = pPrev->m_pNext;

	pPrev->m_pNext = pNode;
	pNode->m_pPrev = pPrev;

	pNext->m_pPrev = pNode;
	pNode->m_pNext = pNext;

	pNode->m_CurrentList = this;

	++m_Count;
}

void List::PopAt( Node* pNode )
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

unsigned int List::Size()
{
	return m_Count;
}

void List::Clear()
{
	bool bRet = IsEmpty();
	while(!this->IsEmpty())
	{

		this->PopFront();
	}
}

bool List::IsEmpty()
{
	return (0 == m_pHead->m_pNext->m_pNext);
}


}//namespace AneUtil