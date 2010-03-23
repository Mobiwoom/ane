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
	// Iocp�� �ɾ��� �۾��� �Ϸ� �Ǹ� ȣ��
	virtual BOOL								ProcessExecute(unsigned int Return, unsigned int Transferred)	= 0;
	// Iocp�� �ɾ��� �۾��� ���� �Ǹ� ȣ��
	virtual BOOL								Error(unsigned int Return, unsigned int Transferred)			= 0;
};
}