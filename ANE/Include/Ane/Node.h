#pragma once
#include "CommonHeader.h"

namespace Ane
{
class LockedList;
class Node
{
	friend class LockedList;
public:
	Node();
	~Node();

protected:
	void										PopThis();

private:
	void										ReSet();

private:
	LockedList*									m_CurrentList;
	Node*										m_pPrev;
	Node*										m_pNext;
};
}//namespace AneUtil