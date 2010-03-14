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
	int											m_MemorySize;
	//	���� ���� �޸� �ּҸ� ����ų ����
	unsigned int								m_Current;
};
}//namespace Ane