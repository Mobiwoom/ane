#include "Ane/Ane/Iocp.h"
//Test ¿ë
#include "Foundation/TimeManager.h"


namespace Ane
{
Iocp::Iocp() 
:Singleton<Iocp>(RELEASE_LEVEL_2),
m_hIocp(0), m_hThread(0), m_NumberOfThread(BASIC_NUMBER_OF_THREAD), m_isStart(FALSE)
{

}

Iocp::~Iocp()
{

}

void Iocp::SetNumberOfThread( unsigned int NumberOfThread)
{
	if(FALSE == m_isStart)
	{
		if(BASIC_NUMBER_OF_THREAD == NumberOfThread)
		{
			SYSTEM_INFO SysTemInfo;
			GetSystemInfo(&SysTemInfo);
			m_NumberOfThread = SysTemInfo.dwNumberOfProcessors * 2 + 1;
		
		}
		else
		{
			m_NumberOfThread = NumberOfThread;
		}
	}
}

void Iocp::Start()
{
	if(FALSE == m_isStart)
	{
		m_hIocp = CreateIoCompletionPort( INVALID_HANDLE_VALUE, NULL, NULL, m_NumberOfThread );
		m_hThread = new HANDLE[m_NumberOfThread];

		for(DWORD i=0; i<m_NumberOfThread; ++i)
		{
			unsigned int threadid;
			m_hThread[i] = (HANDLE)_beginthreadex( NULL, 0, Iocp::CallThread, NULL, 0, &threadid );
		}

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

unsigned int __stdcall Iocp::CallThread( void *pVoid )
{
	UNREFERENCED_PARAMETER(pVoid);
	Iocp::Instance()->Thread();
	return 0;
}

void Iocp::Thread()
{
	DWORD			bytes_transferred	= 0;
	DWORD			completionkey		= 0;
	

	for(;;)
	{
		OVERLAPPED* pOverlapped = NULL;
		BOOL status = FALSE;
		status = GetQueuedCompletionStatus( m_hIocp, &bytes_transferred, static_cast<PULONG_PTR>(&completionkey), &pOverlapped, INFINITE );

		TimeManager* pManager = static_cast<TimeManager*>(pOverlapped);
		pManager->Complete();

	}
}
}//namespace Ane