#pragma once
#include "Common/CommonHeader.h"
#include "Foundation/Singleton.h"
#include "StlCustomize/ane_vector.h"
#include "Thread.h"

namespace Ane
{
	enum {MAX_NUMBER_OF_THREAD = 10,};

class Iocp
	: public Singleton<Iocp>
{
public:
	Iocp();
	virtual ~Iocp();

public:
	// Thread ���� ������
	inline unsigned int							GetNumberOfThread()								{	return m_NumberOfThread;	}

public:
	// ������ Socket�� Iocp�� ���
	void										CreateIocp(const HANDLE Socket);
	// Iocp�� �۾� ���
	BOOL										PostIocp(const LPOVERLAPPED pOverlapped);
	// ������ ���� ��ŭ Thread�� ���� 
	// ���� : MAX_NUMBER_OF_THREAD �� ���� �����Ǵ� Thread�� ������ �ȵ�
	BOOL										CreateThread(unsigned int NumberOfThread);

private:
	friend class Thread;
	// Thread�� Pool���� ����
	BOOL										DestroyThread( unsigned int Index);
		
private:
	// Thread ����
	unsigned int								m_NumberOfThread;
	// Iocp Handle
	HANDLE										m_hIocp;
	// Thread�� ������ container  
	Ane::vector<Thread*>						m_vecThread;
};
}//namespace Ane