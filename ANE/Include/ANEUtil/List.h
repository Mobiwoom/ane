#pragma once

namespace AneUtil
{
class Node;

class List
{
public:
	List();
	virtual ~List();

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