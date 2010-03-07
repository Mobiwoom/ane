#include "Foundation/ISingleton.h"
#include "Foundation/SingletonManager.h"

namespace Ane
{
ISingleton::ISingleton( ReleaseLevel Level /*= RELEASE_LEVEL_1*/ ) :m_Level(Level)
{
	this->Attach();
}

ISingleton::~ISingleton()
{

}

void ISingleton::Attach()
{
	static SingletonManager	m_SingletonManager;
	m_SingletonManager.Attach(this);
}




}//namespace Ane
