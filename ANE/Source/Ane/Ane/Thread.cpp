#include "Ane/Ane/Thread.h"
#include "Ane/Ane/Executor.h"

namespace Ane
{
Thread::Thread()
{

}

Thread::~Thread()
{

}

void Thread::CreateThread(HANDLE hIocp)
{
	unsigned int threadid;
	m_hThread = (HANDLE)_beginthreadex( NULL, 0, Thread::CallThread, &hIocp, 0, &threadid );
}

unsigned int __stdcall Thread::CallThread( void *pHandle )
{
	Thread::Loop(pHandle);
	return 0;
}

void Thread::Loop( void *pHandle )
{
	unsigned long	Transferred			= 0;
	unsigned long	Completionkey		= 0;
	HANDLE*			hIocp = static_cast<HANDLE*>(pHandle); 

	
	for(;;)
	{
		OVERLAPPED* pOverlapped = NULL;
		BOOL bStatus = FALSE;
		bStatus = GetQueuedCompletionStatus( *hIocp, &Transferred, static_cast<unsigned long*>(&Completionkey), &pOverlapped, INFINITE );

		if(TRUE == bStatus)
		{
			Executor* pExecutor = static_cast<Executor*>(pOverlapped);
			if(FALSE == pExecutor->ProcessExecute(Completionkey, Transferred))
				break;
		}
		else
		{
			Executor* pExecutor = static_cast<Executor*>(pOverlapped);
			pExecutor->Error(Completionkey, Transferred);
		}
	}
}
}//namespace Ane

