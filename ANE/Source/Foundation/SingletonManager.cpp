#include "SingletonManager.h"
#include "ISingleton.h"

namespace Ane
{

SingletonManager::SingletonManager()
{

}

SingletonManager::~SingletonManager()
{
	this->Clear();
}

void SingletonManager::Attach( ISingleton* pSingleton )
{
	switch(pSingleton->GetLevel())
	{
	case RELEASE_LEVEL_1:
		this->m_queLevel_1.Push(pSingleton);
		break;
	case RELEASE_LEVEL_2:
		this->m_queLevel_2.Push(pSingleton);
		break;
	case RELEASE_LEVEL_3:
		this->m_queLevel_3.Push(pSingleton);
		break;
	}
}

void SingletonManager::Clear()
{
	ISingleton* pSingleton = NULL;
	while(NULL != (pSingleton = this->m_queLevel_1.Pop()))
	{
		SAFE_DELETE(pSingleton);
	}
	while(NULL != (pSingleton = this->m_queLevel_2.Pop()))
	{
		SAFE_DELETE(pSingleton);
	}
	while(NULL != (pSingleton = this->m_queLevel_3.Pop()))
	{
		SAFE_DELETE(pSingleton);
	}
}
}//namespace Ane
