#pragma once

namespace Ane
{
class LockedList;
class Node
{
public:
	Node();
	virtual ~Node();

	void										ReSet();
	void										PopThis();

	//	void									SetList(List* pList)			{m_CurrentList = pList;}
	//	List*									GetList()						{return m_CurrentList;}

private:
	friend class LockedList;
	LockedList*									m_CurrentList;
	Node*										m_pPrev;
	Node*										m_pNext;
};
}//namespace AneUtil