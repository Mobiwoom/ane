#pragma once
#include "Common/CommonHeader.h"
#include "Foundation/RefCounter.h"

namespace Ane
{
class Memory
	: public Ane::RefCounter
{
public:
	Memory();
	Memory(int MemSize);
	virtual ~Memory();

protected:
	virtual void								OnRelease();

public:
	//	Memory 초기화
	void										IntiMemory();
	//	Size 만큼 메모리 이동 후 메모리 시작 주소 리턴
	char*										AllocMemory(int Size);
	//	현재 메모리 주소 리턴
	char*										CurrentMemory();
	//	메모리 시작 주소 리턴
	char*										GetBeginMemory();
	//	남은 메모리 size 리턴
	int											RemainMemorySize();
	//	메모리 전체 Size 리턴
	int											GetMemorySize();

private:
	//	할당한 메모리
	char*										m_pMemory;
	//	전체 메모리 크기
	int											m_MemorySize;
	//	현재 사용된 메모리 주소를 가르킬 변수
	unsigned int								m_Current;
};
}//namespace Ane