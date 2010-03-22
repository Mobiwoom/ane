#pragma once
#include "Common/CommonHeader.h"
#include "Ane/Ane/Executor.h"

namespace Ane
{
class CloseThread;
class Thread
{
public:
	Thread(UniqueID ID, HANDLE hIocp);
	virtual ~Thread();

public:
	UniqueID									GetUniqueID()					{return m_ThreadID;}
	HANDLE										GetIocp()						{return m_hIocp;}

public:
	void										Create();
	static unsigned int __stdcall				Loop(void *pHandle);
	void										Close();

private:
	HANDLE										m_hThread;
	HANDLE										m_hIocp;
	UniqueID									m_ThreadID;
	CloseThread*								m_pClose;
};

class CloseThread
	: public Ane::IExecutor
{
public:
	CloseThread();
	virtual ~CloseThread();
	virtual BOOL								ProcessExecute(unsigned int Return, unsigned int Transferred);
	virtual BOOL								Error(unsigned int Return, unsigned int Transferred);

};

}//namespace Ane