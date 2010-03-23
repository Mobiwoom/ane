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
	// Thread 갯수 얻어오기
	inline unsigned int							GetNumberOfThread()								{	return m_NumberOfThread;	}

public:
	// 생성된 Socket을 Iocp에 등록
	void										CreateIocp(const HANDLE Socket);
	// Iocp에 작업 등록
	BOOL										PostIocp(const LPOVERLAPPED pOverlapped);
	// 설정한 갯수 만큼 Thread를 만듬 
	// 주의 : MAX_NUMBER_OF_THREAD 수 보다 생성되는 Thread가 많으면 안됨
	BOOL										CreateThread(unsigned int NumberOfThread);

private:
	friend class Thread;
	// Thread를 Pool에서 제거
	BOOL										DestroyThread( unsigned int Index);
		
private:
	// Thread 갯수
	unsigned int								m_NumberOfThread;
	// Iocp Handle
	HANDLE										m_hIocp;
	// Thread를 관리할 container  
	Ane::vector<Thread*>						m_vecThread;
};
}//namespace Ane