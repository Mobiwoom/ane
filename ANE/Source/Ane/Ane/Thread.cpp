#include "Ane/Ane/Thread.h"
#include "Ane/Ane/Executor.h"
#include "Ane/Ane/Iocp.h"

namespace Ane
{
Thread::Thread( UniqueID ID, HANDLE hIocp ) 
: m_ThreadID(ID), m_hIocp(hIocp), m_pClose(NULL)
{
	m_pClose = new CloseThread;
}

Thread::~Thread()
{
	SAFE_DELETE(m_pClose);
}

void Thread::Create()
{
	unsigned int threadid;
	m_hThread = (HANDLE)_beginthreadex( NULL, 0, Thread::Loop, this, 0, &threadid );
}

unsigned int __stdcall Thread::Loop( void *pHandle )
{
	unsigned long	Transferred			= 0;
	unsigned long	Completionkey		= 0;
	Thread* pThread = static_cast<Thread*>(pHandle);
//	HANDLE*			hIocp = static_cast<HANDLE*>(pHandle); 
	HANDLE hIocp = pThread->GetIocp();
	
	for(;;)
	{
		OVERLAPPED* pOverlapped = NULL;
		BOOL bStatus = FALSE;
		bStatus = GetQueuedCompletionStatus( hIocp, &Transferred, static_cast<unsigned long*>(&Completionkey), &pOverlapped, INFINITE );

		if(TRUE == bStatus)
		{
			IExecutor* pExecutor = static_cast<IExecutor*>(pOverlapped);
			if(FALSE == pExecutor->ProcessExecute(Completionkey, Transferred))
				break;
		}
		else
		{
			IExecutor* pExecutor = static_cast<IExecutor*>(pOverlapped);
			pExecutor->Error(Completionkey, Transferred);
		}
	}
	Ane::Iocp::Instance()->DestroyThread(pThread->GetUniqueID());

	return 0;
}

void Thread::Close()
{
	Ane::Iocp::Instance()->PostIocp(m_pClose);
}


CloseThread::CloseThread()
{

}

CloseThread::~CloseThread()
{

}

BOOL CloseThread::ProcessExecute( unsigned int Return, unsigned int Transferred )
{
	UNREFERENCED_PARAMETER(Return);
	UNREFERENCED_PARAMETER(Transferred);
	return FALSE;
}

BOOL CloseThread::Error( unsigned int Return, unsigned int Transferred )
{
	UNREFERENCED_PARAMETER(Return);
	UNREFERENCED_PARAMETER(Transferred);
	return FALSE;
}
}//namespace Ane

