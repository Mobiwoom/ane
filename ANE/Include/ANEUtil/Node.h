#pragma once

namespace AneUtil
{
class List;
class Node
{
public:
	Node();
	virtual ~Node();

	void										ReSet();



	void										PopThis();


	//	void										SetList(List* pList)			{m_CurrentList = pList;}
	//	List*										GetList()						{return m_CurrentList;}

private:
	friend class List;
	List*										m_CurrentList;
	Node*										m_pPrev;
	Node*										m_pNext;
};
}//namespace AneUtil