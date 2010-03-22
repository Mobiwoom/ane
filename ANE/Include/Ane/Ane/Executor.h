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
	virtual BOOL								ProcessExecute(unsigned int Return, unsigned int Transferred)	= 0;
	virtual BOOL								Error(unsigned int Return, unsigned int Transferred)			= 0;
};
}