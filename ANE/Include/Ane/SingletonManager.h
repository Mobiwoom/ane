#pragma once
#include "CommonHeader.h"
#include "LockFreeQueue.h"

namespace Ane
{
enum ReleaseLevel
{
	RELEASE_LEVEL_1,
	RELEASE_LEVEL_2,
	RELEASE_LEVEL_3,
};

class ISingleton
{
	friend class SingletonManager;
public:
	ISingleton(ReleaseLevel Level);
	virtual ~ISingleton();

private:
	ReleaseLevel								GetLevel()						{return m_Level;}

private:
	ReleaseLevel								m_Level;
};


class SingletonManager
{
public:
	SingletonManager();
	~SingletonManager();

public:
	void										Attach(ISingleton* pSingleton);

private:
	void										Clear();

private:
	//TODO : 나중에 stl 커스터마이즈 되면 맵이나 리스트로 바꿔야지
	LockFreeQueue<ISingleton*>					m_queLevel_1;
	LockFreeQueue<ISingleton*>					m_queLevel_2;
	LockFreeQueue<ISingleton*>					m_queLevel_3;
};

}//namespace Ane