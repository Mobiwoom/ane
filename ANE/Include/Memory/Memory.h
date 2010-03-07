#pragma once
#include "Foundation/RefCounter.h"

namespace Ane
{
class Memory
	: public RefCounter
{
public:
	Memory(int MemSize);
	virtual ~Memory();

protected:
	void										OnRelease();
public:
	//	Memory �ʱ�ȭ
	void										IntiMemory();
	//	Size ��ŭ �޸� �̵� �� �޸� ���� �ּ� ����
	char*										AllocMemory(int Size);
	//	���� �޸� �ּ� ����
	char*										CurrentMemory();
	//	�޸� ���� �ּ� ����
	char*										GetBeginMemory();
	//	���� �޸� size ����
	int											RemainMemorySize();
	//	�޸� ��ü Size ����
	int											GetMemorySize();

private:
	//	�Ҵ��� �޸�
	char*										m_pMemory;
	//	��ü �޸� ũ��
	const int									m_MemorySize;
	//	���� ���� �޸� �ּҸ� ����ų ����
	LockFreeCounter								m_Current;
};
}//namespace Ane