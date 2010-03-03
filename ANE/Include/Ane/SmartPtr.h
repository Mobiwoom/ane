#pragma once

namespace Ane
{
template <typename Type>
class Smart_Ptr
{
public:
	typedef Smart_Ptr<Type>	Ptr;

public:
	Smart_Ptr()					{}
	Smart_Ptr(Type* pType)		{}
	virtual ~Smart_Ptr()		{}


private:
	Type*		m_pRef;
	int*		m_pCount;

};
}//namespace AneUtil