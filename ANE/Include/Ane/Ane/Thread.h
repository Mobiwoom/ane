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
	// Iocp Thread pool Index ����
	void										SetIndex(int Index)				{	m_Index = Index;	}
	// Iocp Thread pool Index ������
	int											GetIndex()						{	return m_Index;		}
	// Iocp �ڵ� ������
	HANDLE										GetIocp()						{	return m_hIocp;		}

public:
	// _beginthreadex �� Thread ����
	void										Create();
	// Thread�� ȣ�� �ϴ� ����
	static unsigned int __stdcall				Loop(void *pHandle);
	// Close �޽����� PostIocp �� ���󰡰� �� �۾��� �޴� Thread�� ���� ��.
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