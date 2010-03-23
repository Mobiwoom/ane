#pragma once
#include "Common/CommonHeader.h"

namespace Ane
{
class IExecutor
	: public WSAOVERLAPPED
{
public:
	IExecutor(){hEvent = NULL;}
	virtual ~IExecutor(){}

public:
	// Iocp에 걸었던 작업이 완료 되면 호출
	virtual BOOL								ProcessExecute(unsigned int Return, unsigned int Transferred)	= 0;
	// Iocp에 걸었던 작업이 실패 되면 호출
	virtual BOOL								Error(unsigned int Return, unsigned int Transferred)			= 0;
};
}