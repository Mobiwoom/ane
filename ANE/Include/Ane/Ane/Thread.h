#pragma once
#include "Common/CommonHeader.h"
#include "Ane/Ane/Executor.h"

namespace Ane
{
class Thread
	: public Ane::IExecutor
{
public:
	Thread(int Index, HANDLE hIocp);
	virtual ~Thread();

public:
	// Iocp Thread pool Index 설정
	void										SetIndex(int Index)				{	m_Index = Index;	}
	// Iocp Thread pool Index 얻어오기
	int											GetIndex()						{	return m_Index;		}
	// Iocp 핸들 얻어오기
	HANDLE										GetIocp()						{	return m_hIocp;		}

public:
	// _beginthreadex 로 Thread 생성
	void										Create();
	// Thread가 호출 하는 루프
	static unsigned int __stdcall				Loop(void *pHandle);
	// Close 메시지가 PostIocp 로 날라가고 그 작업을 받는 Thread가 종료 됨.
	void										Close();

private:
	virtual BOOL								ProcessExecute(unsigned int Return, unsigned int Transferred);
	virtual BOOL								Error(unsigned int Return, unsigned int Transferred);

private:
	// Thread Handle
	HANDLE										m_hThread;
	// Iocp Handle
	HANDLE										m_hIocp;
	// Iocp Thread pool Index
	int											m_Index;
};
}//namespace Ane