#include "Ane.h"
#include "vld.h"
#include "boost/shared_ptr.hpp"
#include <list>

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
	TClass* pTest = TClass::Instance();




}