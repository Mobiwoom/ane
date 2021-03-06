#include "Memory/Memory.h"

namespace Ane
{
Memory::Memory()
:m_pMemory(NULL), m_MemorySize(0), m_Current(0)
{

}

Memory::Memory( int MemSize )
:m_pMemory(NULL), m_MemorySize(MemSize), m_Current(0)
{
	m_pMemory = new char[m_MemorySize];
}


Memory::~Memory()
{
	m_Current = 0;
	// 객체가 소멸될때 할당한 메모리도 소멸
	SAFE_DELETE_ARRAY(m_pMemory);
}

void Memory::IntiMemory()
{
	m_Current = 0;
	// 메모리 초기화 
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