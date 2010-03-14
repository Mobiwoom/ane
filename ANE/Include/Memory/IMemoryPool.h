#pragma once

namespace Ane
{
class IMemoryPool
{
public:
	IMemoryPool(){}
	virtual ~IMemoryPool(){}
	virtual void*								Alloc()						= 0;
	virtual void*								Alloc(unsigned int Size)	= 0;
	virtual void								Free(void* pMemory)			= 0;
};
}