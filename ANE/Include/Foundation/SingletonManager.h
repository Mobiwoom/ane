#pragma once
#include "Common/CommonHeader.h"
#include "Foundation/LockFreeQueue.h"

namespace Ane
{
class ISingleton;
// ���� : �� Class �� ���� ���� ������.
class SingletonManager
{
	friend class ISingleton;
private:
	SingletonManager();
	~SingletonManager();

private:
	// Singleton �� ���
	void										Attach(ISingleton* pSingleton);

private:
	// Singleton ��� �Ҹ�
	void										Clear();

private:
	//TODO : ���߿� stl Ŀ���͸����� �Ǹ� ���̳� ����Ʈ�� �ٲ����
	LockFreeQueue<ISingleton*>					m_queLevel_1;
	LockFreeQueue<ISingleton*>					m_queLevel_2;
	LockFreeQueue<ISingleton*>					m_queLevel_3;
};
}//namespace Ane