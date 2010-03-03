#pragma once

namespace Ane
{
class Node;
class LockedList
{
public:
	LockedList();
	virtual ~LockedList();

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
	Node*										m_pHead;
	Node*										m_pTail;
	unsigned int								m_Count;
};

}//namespace AneUtil