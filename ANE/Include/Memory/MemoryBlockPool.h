#pragma once
#include "IMemoryPool.h"
#include "Common/CommonHeader.h"
#include "Foundation/LockFreeQueue.h"
#include "Foundation/Singleton.h"
#include "Memory/Memory.h"

enum
{
	DEFUALT_MEMORY_BLOCK_SIZE	= 1024,
	MAX_SIZE_OF_MEMORY_BLOCK	= 65536,
	NUMBER_OF_BLOCK_SIZE		= 10,
};

namespace Ane
{
class MemoryBlockPool
	: public Ane::IMemoryPool
	, public Ane::Singleton<MemoryBlockPool>
{
public:
	MemoryBlockPool();
	virtual ~MemoryBlockPool();

public:
	void*									Alloc();
	void*									Alloc(unsigned int Size);
	void									Free(void* pMemory);

private:
	void									Destroy();

private:
	Ane::LockFreeQueue<Ane::Memory*>		m_queMemoryBlock[NUMBER_OF_BLOCK_SIZE];
};
}//namespace Ane
