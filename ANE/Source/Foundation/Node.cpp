#include "Foundation/Node.h"
#include "Foundation/LockedList.h"

namespace Ane
{
Node::Node()
	:m_pPrev(NULL), m_pNext(NULL), m_CurrentList(NULL)
{

}
Node::~Node()
{

}

void Node::PopThis()
{
	this->m_CurrentList->PopAt(this);
}

void Node::ReSet()
{
	m_pPrev			= NULL;
	m_pNext			= NULL;
	m_CurrentList	= NULL;
}
}//namespace AneUtil