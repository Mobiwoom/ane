#include <conio.h>
#include "Ane.h"
#include "vld.h"
#include "boost/shared_ptr.hpp"
#include "Foundation/Timer.h"

class TClass
	: public Ane::Timer
{
public:
	TClass()
	{

	}
	virtual ~TClass(){}
	void OnTimer(Ane::Time* pTime)
	{

	}
	void Test()
	{
		this->SetTimer(&m_Time, 1000);
	}
public:

	Ane::Time m_Time;

};

void main()
{
	TClass Temp;
	Temp.Test();

	_getch();
}