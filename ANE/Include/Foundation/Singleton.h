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
	// 按眉 掘绢坷扁
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
	// 积己等 按眉啊 绝阑版快 按眉 积己
	if(m_pInstance == NULL)	
	{
		m_pInstance = new Type;
	}
	// 按眉 府畔
	return m_pInstance;
}
}//namespace Ane