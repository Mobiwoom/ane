#pragma once
#include "Common/CommonHeader.h"
#include "Memory/Memory.h"
#include "Foundation/Ptr.h"

// TODO : Receive 만들면 만들기 시작 할꺼임
namespace Ane
{
class Buffer
	: public WSABUF
{
public:
	Buffer()
	{

	}
	Buffer(int Size)
	{

	}
	Buffer(Ane::Ptr<Memory> pMemory, char* pBuf)
	{

	}
	virtual ~Buffer()
	{

	}


private:

};
}//namespace Ane