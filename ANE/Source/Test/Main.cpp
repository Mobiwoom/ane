#include "AneUtil.h"

class Test
{
public:
	int m_Num;
};

void main()
{
	AneUtil::LockFreeQueue<Test>			queTest;
	Test* pTest = new Test;
	Test temp ;
	queTest.Push(temp);

}