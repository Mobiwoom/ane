#pragma once
#include "Common/CommonHeader.h"
#include "Foundation/Singleton.h"

namespace Ane
{
	enum {BASIC_NUMBER_OF_THREAD = 0,};

class Iocp
	: public Singleton<Iocp>
{
public:
	Iocp();
	virtual ~Iocp();

public:
	void										SetNumberOfThread(unsigned int NumberOfThread = BASIC_NUMBER_OF_THREAD);
	void										Start();
	void										CreateIocp(const HANDLE Socket);
	BOOL										PostIocp(const LPOVERLAPPED pOverlapped);
	static unsigned int __stdcall				CallThread(void *pVoid);
	void										Thread();

	const BOOL									IsStart()										{return m_isStart;}
		
private:
	HANDLE										m_hIocp;
	HANDLE*										m_hThread;
	unsigned int								m_NumberOfThread;
	BOOL										m_isStart;
};
}//namespace Ane