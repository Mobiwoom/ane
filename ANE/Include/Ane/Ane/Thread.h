#pragma once
#include "Common/CommonHeader.h"

namespace Ane
{
class Thread
{
public:
	Thread();
	virtual ~Thread();

	void										CreateThread(HANDLE hIocp);
	static unsigned int __stdcall				CallThread(void *pHandle);
	static void									Loop(void *pHandle);

private:
	HANDLE										m_hThread;
};

}//namespace Ane