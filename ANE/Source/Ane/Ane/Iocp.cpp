#include "Ane/Ane/Iocp.h"
#include "Ane/Ane/Thread.h"

namespace Ane
{
Iocp::Iocp() 
:Singleton<Iocp>(RELEASE_LEVEL_2),
m_hIocp(0), m_NumberOfThread(0)
{
	// Iocp ����
	m_hIocp = CreateIoCompletionPort( INVALID_HANDLE_VALUE, NULL, NULL, MAX_NUMBER_OF_THREAD );
	// container�� MAX_NUMBER_OF_THREAD���� ��ŭ �ʱ�ȭ
	m_vecThread.resize(MAX_NUMBER_OF_THREAD);
}

Iocp::~Iocp()
{

}

BOOL Iocp::CreateThread( unsigned int NumberOfThread )
{
	// Thread ������ MAX_NUMBER_OF_THREAD ũ�� �ȵ� �� ���� Thread�� �ʿ��ϸ� enum MAX_NUMBER_OF_THREAD �� ����
	ASSERT(m_NumberOfThread + NumberOfThread > MAX_NUMBER_OF_THREAD);

	int Index = 0;
	for(unsigned int i=0; i<NumberOfThread; ++i)
	{
		for(Index; Index<MAX_NUMBER_OF_THREAD; ++Index)	
		{
			if(NULL == m_vecThread[Index])	// �� ������ ������ ���ڸ��� ������ ����
			{
				// Thread ����
				Ane::Thread* pThread = new Ane::Thread(Index++, m_hIocp); // TODO : ���� ������ ���� �Ǵ��� Ȯ��
				// container �� ������ Thread ������ ����
				m_vecThread[Index] = pThread;
				// Thread ���� ����
				++m_NumberOfThread;
				break;
			}
		}
	}
	return TRUE;
}

BOOL Iocp::DestroyThread( unsigned int Index )
{
	ASSERT(Index < MAX_NUMBER_OF_THREAD);
	
	// �ش� Index �� �������� FALSE ����
	if(NULL == m_vecThread[Index])
		return FALSE;

	// Thread Class �� �ε��� �ʱ�ȭ ���ֱ�
	m_vecThread[Index]->SetIndex(-1);
	// container �� ������ ����
	m_vecThread[Index] = NULL;
	//Thread ���� ����
	--m_NumberOfThread;

	// Thread ���� ����
	return TRUE;
}

void Iocp::CreateIocp( HANDLE Socket )
{
	// Iocp�� Handle ���
	CreateIoCompletionPort( Socket, m_hIocp, 0, 0 );
}

BOOL Iocp::PostIocp( LPOVERLAPPED pOverlapped )
{
	// Iocp�� �۾� ��� 
	return PostQueuedCompletionStatus(m_hIocp, 0, NULL, pOverlapped);
}
}//namespace Ane