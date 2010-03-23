#include "Foundation/ISingleton.h"
#include "Foundation/SingletonManager.h"

namespace Ane
{
ISingleton::ISingleton(ReleaseLevel Level) 
:m_Level(Level)
{
	this->Attach();
}

ISingleton::~ISingleton()
{

}

void ISingleton::Attach()
{
	// static 변수로 프로세서가 종료 될때 소멸됨
	static SingletonManager	m_SingletonManager;
	// 
	m_SingletonManager.Attach(this);
}
}//namespace Ane
