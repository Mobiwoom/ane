#pragma once
#include "Common/CommonHeader.h"
#include "CriticalSection.h"

namespace Ane
{
class Node;
class LockedList
{
public:
	LockedList();
	~LockedList();

public:
	void										PushBack(Node* pNode);
	void										PushFront(Node* pNode);
	Node*										PopBack();
	Node*										PopFront();
	unsigned int								Size();
	void										Clear();
	bool										IsEmpty();

private:
	void										PushNext(Node* pPrev, Node* pNode);
	void										PopAt(Node* pNode);

private:
	friend class Node;
	Ane::CriticalSection						m_Lock;
	Node*										m_pHead;
	Node*										m_pTail;
	unsigned int								m_Count;
};

}//namespace AneUtil