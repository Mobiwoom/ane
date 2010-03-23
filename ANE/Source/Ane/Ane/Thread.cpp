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
	// Thread ����
	unsigned int threadid;
	m_hThread = (HANDLE)_beginthreadex( NULL, 0, Thread::Loop, this, 0, &threadid );
}

unsigned int __stdcall Thread::Loop( void *pHandle )
{
	unsigned long	Transferred			= 0;
	unsigned long	Completionkey		= 0;
	// ������ Thread Class ��ü ������
	Thread* pThread = static_cast<Thread*>(pHandle);
	HANDLE hIocp = pThread->GetIocp();
	
	for(;;)
	{
		OVERLAPPED* pOverlapped = NULL;
		BOOL bStatus = FALSE;
		// �۾� �Ϸ� ���
		bStatus = GetQueuedCompletionStatus( hIocp, &Transferred, static_cast<unsigned long*>(&Completionkey), &pOverlapped, INFINITE );

		if(TRUE == bStatus)
		{
			IExecutor* pExecutor = static_cast<IExecutor*>(pOverlapped);
			// ���� : FALSE �� ���� �Ǹ� Thread�� �����.
			if(FALSE == pExecutor->ProcessExecute(Completionkey, Transferred))
				break;
		}
		else
		{
			IExecutor* pExecutor = static_cast<IExecutor*>(pOverlapped);
			pExecutor->Error(Completionkey, Transferred);
		}
	}
	// Iocp Thread Pool ���� ��ü ���� �ϱ�
	Ane::Iocp::Instance()->DestroyThread(pThread->GetIndex());

	// TODO : ���⼭ ������ �Ǵ��� Ȯ�� �ʿ�
	// Thread �����
	SAFE_DELETE(pThread);
	return 0;
}

void Thread::Close()
{
	// IOCP �� ���� �۾� ������
	Ane::Iocp::Instance()->PostIocp(this);
}

BOOL Thread::ProcessExecute( unsigned int Return, unsigned int Transferred )
{
	UNREFERENCED_PARAMETER(Return);
	UNREFERENCED_PARAMETER(Transferred);
	// Thread ���ᰡ �����̹Ƿ� FALSE �� ����
	return FALSE;
}

BOOL Thread::Error( unsigned int Return, unsigned int Transferred )
{
	UNREFERENCED_PARAMETER(Return);
	UNREFERENCED_PARAMETER(Transferred);
	// Thread ���ᰡ �����̹Ƿ� FALSE �� ����
	return FALSE;
}
}//namespace Ane

