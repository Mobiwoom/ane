#include "Memory/Memory.h"

namespace Ane
{
Memory::Memory( int MemSize )
:m_pMemory(NULL), m_MemorySize(MemSize), m_Current(0)
{
	m_pMemory = new char[m_MemorySize];
}

Memory::~Memory()
{
	m_Current = 0;
	SAFE_DELETE_ARRAY(m_pMemory);
}

void Memory::IntiMemory()
{
	m_Current = 0;
	ZeroMemory(m_pMemory, m_MemorySize);
}

void Memory::OnRelease()
{
	// TODO : MemoryBlock Pool 로 돌려주기
}

char* Memory::AllocMemory( int Size )
{
	char* pRet = &m_pMemory[m_Current];
	m_Current += Size;
	return pRet;
}

char* Memory::CurrentMemory()
{
	return &m_pMemory[m_Current];
}

char* Memory::GetBeginMemory()
{
	return &m_pMemory[0];
}

int Memory::RemainMemorySize()
{
	return m_MemorySize - m_Current;
}

int Memory::GetMemorySize()
{
	return m_MemorySize;
}


}//namespace Ane