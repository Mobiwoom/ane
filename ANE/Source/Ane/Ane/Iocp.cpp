#include "Ane/Ane/Iocp.h"
#include "Ane/Ane/Thread.h"

namespace Ane
{
Iocp::Iocp() 
:Singleton<Iocp>(RELEASE_LEVEL_2),
m_hIocp(0), m_NumberOfThread(0)
{
	// Iocp 생성
	m_hIocp = CreateIoCompletionPort( INVALID_HANDLE_VALUE, NULL, NULL, MAX_NUMBER_OF_THREAD );
	// container를 MAX_NUMBER_OF_THREAD갯수 만큼 초기화
	m_vecThread.resize(MAX_NUMBER_OF_THREAD);
}

Iocp::~Iocp()
{

}

BOOL Iocp::CreateThread( unsigned int NumberOfThread )
{
	// Thread 갯수가 MAX_NUMBER_OF_THREAD 크면 안됨 더 많은 Thread가 필요하면 enum MAX_NUMBER_OF_THREAD 를 수정
	ASSERT(m_NumberOfThread + NumberOfThread > MAX_NUMBER_OF_THREAD);

	int Index = 0;
	for(unsigned int i=0; i<NumberOfThread; ++i)
	{
		for(Index; Index<MAX_NUMBER_OF_THREAD; ++Index)	
		{
			if(NULL == m_vecThread[Index])	// 빈 번지가 있으면 그자리에 포인터 저장
			{
				// Thread 생성
				Ane::Thread* pThread = new Ane::Thread(Index++, m_hIocp); // TODO : 정상 적으로 생성 되는지 확인
				// container 에 생성된 Thread 포인터 저장
				m_vecThread[Index] = pThread;
				// Thread 갯수 증가
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
	
	// 해당 Index 가 비었을경우 FALSE 리턴
	if(NULL == m_vecThread[Index])
		return FALSE;

	// Thread Class 에 인덱스 초기화 해주기
	m_vecThread[Index]->SetIndex(-1);
	// container 에 포인터 제거
	m_vecThread[Index] = NULL;
	//Thread 갯수 감소
	--m_NumberOfThread;

	// Thread 제거 성공
	return TRUE;
}

void Iocp::CreateIocp( HANDLE Socket )
{
	// Iocp에 Handle 등록
	CreateIoCompletionPort( Socket, m_hIocp, 0, 0 );
}

BOOL Iocp::PostIocp( LPOVERLAPPED pOverlapped )
{
	// Iocp에 작업 등록 
	return PostQueuedCompletionStatus(m_hIocp, 0, NULL, pOverlapped);
}
}//namespace Ane