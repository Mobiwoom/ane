#pragma once
#include "CommonHeader.h"
#include "ISingleton.h"

namespace Ane
{

template <typename Type>
class Singleton
	: public ISingleton
{
public:
	Singleton(ReleaseLevel Level = Ane::RELEASE_LEVEL_1);
	virtual ~Singleton();

public:
	static Type*								Instance();
	
private:
	static Type*								m_pInstance;
};

template <class Type>
Type* Singleton<Type>::m_pInstance = NULL;

template <class Type>
Singleton<Type>::Singleton(ReleaseLevel Level)
: ISingleton(Level)
{
	
}

template <class Type>
Singleton<Type>::~Singleton()
{

}

template <class Type>
Type* Singleton<Type>::Instance()
{
	if(m_pInstance == NULL)
	{
		m_pInstance = new Type;
	}
	return m_pInstance;
}
}//namespace Ane