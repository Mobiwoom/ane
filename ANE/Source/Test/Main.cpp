#include "Ane.h"
#include "vld.h"
#include "boost/shared_ptr.hpp"
#include <list>

class TClass
	: public Ane::Singleton<TClass>
{
public:
	TClass()
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