#pragma once
#include "Common/CommonHeader.h"
#include "Foundation/LockFreeQueue.h"

namespace Ane
{
class ISingleton;
// 주의 : 이 Class 를 생성 하지 마세요.
class SingletonManager
{
	friend class ISingleton;
private:
	SingletonManager();
	~SingletonManager();

private:
	// Singleton 을 등록
	void										Attach(ISingleton* pSingleton);

private:
	// Singleton 모두 소멸
	void										Clear();

private:
	//TODO : 나중에 stl 커스터마이즈 되면 맵이나 리스트로 바꿔야지
	LockFreeQueue<ISingleton*>					m_queLevel_1;
	LockFreeQueue<ISingleton*>					m_queLevel_2;
	LockFreeQueue<ISingleton*>					m_queLevel_3;
};
}//namespace Ane