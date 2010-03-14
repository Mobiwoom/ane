#include "Foundation/Timer.h"
#include "Foundation/TimeManager.h"

namespace Ane
{
Timer::Timer()
{

}

Timer::~Timer()
{

}

void Timer::SetTimer( Ane::Time* pTime, unsigned int Interval )
{
	pTime->m_Interval = Interval;
	
	TimeManager::Instance()->AttachTimer(pTime, this);
}

void Timer::KillTimer( Ane::Time* pTime )
{
	TimeManager::Instance()->DetachTimer(pTime);
}
}//namespace Ane