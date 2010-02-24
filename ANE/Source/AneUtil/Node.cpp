#include "Node.h"
#include "List.h"

namespace AneUtil
{
Node::Node()
	:m_pPrev(0), m_pNext(0), m_CurrentList(0)
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
	m_pPrev			= 0;
	m_pNext			= 0;
	m_CurrentList	= 0;
}
}//namespace AneUtil