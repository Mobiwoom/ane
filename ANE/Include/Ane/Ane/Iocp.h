#pragma once
#include "Common/CommonHeader.h"
#include "Foundation/Singleton.h"
#include "StlCustomize/ane_map.h"
#include "Thread.h"

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
	
	

	const BOOL									IsStart()										{return m_isStart;}
		
private:
	Ane::map<unsigned int, Thread*>				m_mapThread;
	HANDLE										m_hIocp;
	unsigned int								m_NumberOfThread;
	BOOL										m_isStart;
};
}//namespace Ane