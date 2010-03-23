#pragma once
#include "Common/CommonHeader.h"
#include "Foundation/ISingleton.h"

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
	// ��ü ������
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
	// ������ ��ü�� ������� ��ü ����
	if(m_pInstance == NULL)	
	{
		m_pInstance = new Type;
	}
	// ��ü ����
	return m_pInstance;
}
}//namespace Ane