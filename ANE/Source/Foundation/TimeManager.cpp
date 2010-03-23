#include "Foundation/TimeManager.h"
#include "Ane/Ane/Iocp.h"

namespace Ane
{
TimeManager::TimeManager() 
:Ane::Singleton<TimeManager>(RELEASE_LEVEL_2),m_isStart(FALSE)
{
	Ane::Iocp::Instance()->CreateThread(1);
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


		Sleep(1);//TODO : 슬립 안부르고 cpu 점유율 내리는 방법을 찾아야 함

		Iocp::Instance()->PostIocp(this);
	}

	m_Lock.Leave();
}

void TimeManager::AttachTimer( Ane::Time* pTime, Ane::Timer* pTimer )
{
	m_Lock.Enter();
	UNREFERENCED_PARAMETER(pTime);
	UNREFERENCED_PARAMETER(pTimer);
	m_Lock.Leave();
}

void TimeManager::DetachTimer( Ane::Time* pTime )
{
	m_Lock.Enter();
	// TODO : OnTimer에서 KillTimer부르면 문제 있을듯.ㅋ
	UNREFERENCED_PARAMETER(pTime);
	m_Lock.Leave();
}

void TimeManager::AttachAlarm( Ane::Time* pTime, Ane::Timer* pTimer )
{
	UNREFERENCED_PARAMETER(pTime);
	UNREFERENCED_PARAMETER(pTimer);
}

}//namespace Ane