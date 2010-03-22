#include "Ane/Ane/Iocp.h"
#include "Ane/Ane/Thread.h"



namespace Ane
{
Iocp::Iocp() 
:Singleton<Iocp>(RELEASE_LEVEL_2),
m_hIocp(0), m_isStart(FALSE), m_UniqueThreadID(0)
{
	m_hIocp = CreateIoCompletionPort( INVALID_HANDLE_VALUE, NULL, NULL, MAX_NUMBER_OF_THREAD );
}

Iocp::~Iocp()
{

}

BOOL Iocp::CreateThread( unsigned int NumberOfThread )
{
	ASSERT(m_UniqueThreadID + NumberOfThread > m_mapThread.size());
	Ane::Thread* pThread = new Ane::Thread(++m_UniqueThreadID, m_hIocp);
	m_mapThread.insert(Ane::map<unsigned int, Thread*>::value_type(m_UniqueThreadID, pThread));
	return TRUE;
}

BOOL Iocp::DestroyThread( UniqueID ID )
{
	Ane::map<unsigned int, Thread*>::iterator it = m_mapThread.find(ID);
	if(it == m_mapThread.end())
		return FALSE;

	m_mapThread.erase(it);
	return TRUE;
}


void Iocp::Start()
{
	if(FALSE == m_isStart)
	{
		m_isStart = TRUE;
	}
}

void Iocp::CreateIocp( HANDLE Socket )
{
	CreateIoCompletionPort( Socket, m_hIocp, 0, 0 );
}

BOOL Iocp::PostIocp( LPOVERLAPPED pOverlapped )
{
	return PostQueuedCompletionStatus(m_hIocp, 0, NULL, pOverlapped);
}



//void Iocp::Thread()
//{
//	DWORD			bytes_transferred	= 0;
//	DWORD			completionkey		= 0;
//	
//
//	for(;;)
//	{
//		OVERLAPPED* pOverlapped = NULL;
//		BOOL status = FALSE;
//		status = GetQueuedCompletionStatus( m_hIocp, &bytes_transferred, static_cast<PULONG_PTR>(&completionkey), &pOverlapped, INFINITE );
//
//		TimeManager* pManager = static_cast<TimeManager*>(pOverlapped);
//		pManager->Complete();
//
//	}
//}
}//namespace Ane