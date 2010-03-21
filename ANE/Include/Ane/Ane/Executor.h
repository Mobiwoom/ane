#pragma once
#include "Common/CommonHeader.h"

namespace Ane
{
class Executor
	: public WSAOVERLAPPED
{
public:
	Executor(){hEvent = NULL;}
	virtual ~Executor(){}

public:
	virtual BOOL								ProcessExecute(unsigned int Return, unsigned int Transferred)	= 0;
	virtual BOOL								Error(unsigned int Return, unsigned int Transferred)			= 0;
};
}