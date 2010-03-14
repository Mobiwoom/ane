#include "Memory/MemoryBlockPool.h"

namespace Ane
{
MemoryBlockPool::MemoryBlockPool()
: Singleton<MemoryBlockPool>(RELEASE_LEVEL_3)
{

}

MemoryBlockPool::~MemoryBlockPool()
{
	this->Destroy();
}

void* MemoryBlockPool::Alloc()
{
	Memory* pMemory = new Memory(DEFUALT_MEMORY_BLOCK_SIZE);
	return pMemory;
}

void* MemoryBlockPool::Alloc( unsigned int Size )
{
	Memory* pMemory = NULL;
	if(Size <= 128)
	{
		pMemory = this->m_queMemoryBlock[0].Pop();
		if(pMemory == NULL)
			pMemory = ::new Memory(128);
	}
	else if(Size <= 256)
	{
		pMemory = this->m_queMemoryBlock[1].Pop();
		if(pMemory == NULL)
			pMemory = new Memory(256);
	}
	else if(Size <= 512)
	{
		pMemory =this-> m_queMemoryBlock[2].Pop();
		if(pMemory == NULL)
			pMemory = new Memory(512);
	}
	else if(Size <= 1024)
	{
		pMemory = this->m_queMemoryBlock[3].Pop();
		if(pMemory == NULL)
			pMemory = new Memory(1024);
	}
	else if(Size <= 2048)
	{
		pMemory = this->m_queMemoryBlock[4].Pop();
		if(pMemory == NULL)
			pMemory = new Memory(2048);
	}
	else if(Size <= 4096)
	{
		pMemory = this->m_queMemoryBlock[5].Pop();
		if(pMemory == NULL)
			pMemory = new Memory(4096);
	}
	else if(Size <= 8192)
	{
		pMemory = this->m_queMemoryBlock[6].Pop();
		if(pMemory == NULL)
			pMemory = new Memory(8192);
	}
	else if(Size <= 16384)
	{
		pMemory = this->m_queMemoryBlock[7].Pop();
		if(pMemory == NULL)
			pMemory = new Memory(16384);
	}
	else if(Size <= 32768)
	{
		pMemory = this->m_queMemoryBlock[8].Pop();
		if(pMemory == NULL)
			pMemory = new Memory(32768);
	}
	else if(Size <= 65536)
	{
		pMemory = this->m_queMemoryBlock[9].Pop();
		if(pMemory == NULL)
			pMemory = new Memory(65536);
	}
	else
	{
		//예외 처리
	}
	
	return pMemory;
}

void MemoryBlockPool::Free( void* pMemory )
{
	Memory* pMem = reinterpret_cast<Memory*>(pMemory);
	int nSize = pMem->GetMemorySize();
	if(nSize == 128)
		m_queMemoryBlock[0].Push(pMem);
	else if(nSize == 256)
		m_queMemoryBlock[1].Push(pMem);
	else if(nSize == 512)
		m_queMemoryBlock[2].Push(pMem);
	else if(nSize == 1024)
		m_queMemoryBlock[3].Push(pMem);
	else if(nSize == 2048)
		m_queMemoryBlock[4].Push(pMem);
	else if(nSize == 4096)
		m_queMemoryBlock[5].Push(pMem);
	else if(nSize == 8192)
		m_queMemoryBlock[6].Push(pMem);
	else if(nSize == 16384)
		m_queMemoryBlock[7].Push(pMem);
	else if(nSize == 32768)
		m_queMemoryBlock[8].Push(pMem);
	else if(nSize == 65536)
		m_queMemoryBlock[9].Push(pMem);
}

void MemoryBlockPool::Destroy()
{
	for(int i=0; i<NUMBER_OF_BLOCK_SIZE; ++i)
	{
		for(;;)
		{
			Memory* pMemory = m_queMemoryBlock[i].Pop();
			if(pMemory == NULL)
				break;
			else
				delete pMemory;
		}
	}
}
}//namespace Ane