#include "Foundation/TimeManager.h"
#include "Ane/Ane/Iocp.h"

namespace Ane
{
TimeManager::TimeManager() 
:Ane::Singleton<TimeManager>(RELEASE_LEVEL_2),m_isStart(FALSE)
{
	BOOL isStart = Ane::Iocp::Instance()->IsStart();
	if(FALSE == isStart)
	{
		Ane::Iocp::Instance()->SetNumberOfThread(1);
		Ane::Iocp::Instance()->Start();
	}
	this->Start();
}

TimeManager::~TimeManager()
{

}

void TimeManager::Start()
{
	m_isStart = TRUE;
	Iocp::Instance()->PostIocp(this);
}

void TimeManager::Stop()
{
	m_isStart = FALSE;
}

void TimeManager::Complete()
{
	m_Lock.Enter();

	if(TRUE == m_isStart)
	{


		Sleep(1);//TODO : ���� �Ⱥθ��� cpu ������ ������ ����� ã�ƾ� ��

		Iocp::Instance()->PostIocp(this);
	}

	m_Lock.Leave();
}

void TimeManager::AttachTimer( Ane::Time* pTime, Ane::Timer* pTimer )
{
	m_Lock.Enter();

	m_Lock.Leave();
}

void TimeManager::DetachTimer( Ane::Time* pTime )
{
	m_Lock.Enter();
	// TODO : OnTimer���� KillTimer�θ��� ���� ������.��

	m_Lock.Leave();
}

void TimeManager::AttachAlarm( Ane::Time* pTime, Ane::Timer* pTimer )
{

}

}//namespace Ane