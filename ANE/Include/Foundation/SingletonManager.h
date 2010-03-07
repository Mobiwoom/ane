#pragma once
#include "CommonHeader.h"
#include "LockFreeQueue.h"

namespace Ane
{
class ISingleton;
class SingletonManager
{
	friend class ISingleton;
private:
	SingletonManager();
	~SingletonManager();

public:
	void										Attach(ISingleton* pSingleton);

private:
	void										Clear();

private:
	//TODO : ���߿� stl Ŀ���͸����� �Ǹ� ���̳� ����Ʈ�� �ٲ����
	LockFreeQueue<ISingleton*>					m_queLevel_1;
	LockFreeQueue<ISingleton*>					m_queLevel_2;
	LockFreeQueue<ISingleton*>					m_queLevel_3;
};
}//namespace Ane