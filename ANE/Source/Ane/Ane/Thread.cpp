#include "Ane/Ane/Thread.h"
#include "Ane/Ane/Executor.h"
#include "Ane/Ane/Iocp.h"

namespace Ane
{
Thread::Thread(int Index, HANDLE hIocp ) 
: m_Index(Index), m_hIocp(hIocp)
{

}

Thread::~Thread()
{
}

void Thread::Create()
{
	// Thread 생성
	unsigned int threadid;
	m_hThread = (HANDLE)_beginthreadex( NULL, 0, Thread::Loop, this, 0, &threadid );
}

unsigned int __stdcall Thread::Loop( void *pHandle )
{
	unsigned long	Transferred			= 0;
	unsigned long	Completionkey		= 0;
	// 생성된 Thread Class 객체 포인터
	Thread* pThread = static_cast<Thread*>(pHandle);
	HANDLE hIocp = pThread->GetIocp();
	
	for(;;)
	{
		OVERLAPPED* pOverlapped = NULL;
		BOOL bStatus = FALSE;
		// 작업 완료 대기
		bStatus = GetQueuedCompletionStatus( hIocp, &Transferred, static_cast<unsigned long*>(&Completionkey), &pOverlapped, INFINITE );

		if(TRUE == bStatus)
		{
			IExecutor* pExecutor = static_cast<IExecutor*>(pOverlapped);
			// 주의 : FALSE 가 리턴 되면 Thread가 종료됨.
			if(FALSE == pExecutor->ProcessExecute(Completionkey, Transferred))
				break;
		}
		else
		{
			IExecutor* pExecutor = static_cast<IExecutor*>(pOverlapped);
			pExecutor->Error(Completionkey, Transferred);
		}
	}
	// Iocp Thread Pool 에서 객체 제거 하기
	Ane::Iocp::Instance()->DestroyThread(pThread->GetIndex());

	// TODO : 여기서 지워두 되는지 확인 필요
	// Thread 지우기
	SAFE_DELETE(pThread);
	return 0;
}

void Thread::Close()
{
	// IOCP 에 종료 작업 보내기
	Ane::Iocp::Instance()->PostIocp(this);
}

BOOL Thread::ProcessExecute( unsigned int Return, unsigned int Transferred )
{
	UNREFERENCED_PARAMETER(Return);
	UNREFERENCED_PARAMETER(Transferred);
	// Thread 종료가 목적이므로 FALSE 를 리턴
	return FALSE;
}

BOOL Thread::Error( unsigned int Return, unsigned int Transferred )
{
	UNREFERENCED_PARAMETER(Return);
	UNREFERENCED_PARAMETER(Transferred);
	// Thread 종료가 목적이므로 FALSE 를 리턴
	return FALSE;
}
}//namespace Ane

