#pragma once
#include "Common/CommonHeader.h"
#include "Foundation/Singleton.h"
#include "StlCustomize/ane_map.h"
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
	BOOL										IsStart()										{return this->m_isStart;}

public:
	void										Start();
	void										CreateIocp(const HANDLE Socket);
	BOOL										PostIocp(const LPOVERLAPPED pOverlapped);

	BOOL										CreateThread(unsigned int NumberOfThread);

private:
	friend class Thread;
	BOOL										DestroyThread(UniqueID ID);
		
private:
	Ane::map<unsigned int, Thread*>				m_mapThread;
	UniqueID									m_UniqueThreadID;
	HANDLE										m_hIocp;
	BOOL										m_isStart;
};
}//namespace Ane