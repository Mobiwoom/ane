#include "Ane.h"
#include "vld.h"
#include "boost/shared_ptr.hpp"

class TClass
	: public Ane::Singleton<TClass>
{
public:
	TClass()
		:Ane::Singleton<TClass>(Ane::RELEASE_LEVEL_2)
	{

	}
	virtual ~TClass(){}
public:

	int NumA;
	int NumB;
};

void main()
{
	Ane::list<int*> m_list;

	int* pA = new int;

	m_list.push_back(pA);
	
}