#include "Ane.h"
#include "vld.h"

class Test
{
public:
	int m_Num;
};

void main()
{
	Ane::LockFreeQueue<Test*>			queTest;
	Test* pTest = new Test;
	queTest.Push(pTest);

}