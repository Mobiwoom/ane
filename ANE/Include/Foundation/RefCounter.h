#pragma once
#include "Common/CommonHeader.h"
#include "LockFreeCounter.h"

namespace Ane
{
class RefCounter
{
public:
	RefCounter():m_RefCounter(0)				{	}
	virtual ~RefCounter()						{	}

public:
	// ���� ī���� ������
	int 										GetRef()					{	return this->m_RefCounter;	}
	// ���� ī���� �ʱ�ȭ
	void										InitRef()					{	this->m_RefCounter = 0;		}
	// ���� ī���� ����
	void										AddRef()					{	++this->m_RefCounter;		}
	// ���� ī���� ���� �� ���� ī���Ͱ� 0�̸� OnRelease() ȣ��
	void										Release()					{	--this->m_RefCounter;	if(this->m_RefCounter == 0)	this->OnRelease();	}

protected:
	// ��� ���� ��ü���� ������ ���� ������ ��ü�� ����
	virtual void								OnRelease()					{	ANE_DELETE(this);	}

private:
	Ane::LockFreeCounter						m_RefCounter;
};
}//namespace Ane