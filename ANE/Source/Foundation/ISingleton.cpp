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
	// static ������ ���μ����� ���� �ɶ� �Ҹ��
	static SingletonManager	m_SingletonManager;
	// 
	m_SingletonManager.Attach(this);
}
}//namespace Ane
