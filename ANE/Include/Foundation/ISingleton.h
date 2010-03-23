#pragma once

namespace Ane
{
// 삭제 레벨 
// 프로세서가 종료 될때 RELEASE_LEVEL_1, RELEASE_LEVEL_2, RELEASE_LEVEL_3 순서대로 삭제됨
enum ReleaseLevel
{
	RELEASE_LEVEL_0 = 0,		// 주의 : 레벨 0일때는 소멸 순서를 보장해주지 않음
	RELEASE_LEVEL_1 = 1,
	RELEASE_LEVEL_2 = 2,
	RELEASE_LEVEL_3 = 3,		
	// TODO : 레벨 5정도까지 만들어서 IOCP나 TIMER들까지도 안전하게 마지막에 종료 될수 있게 추가
};

class ISingleton
{
public:	
	ISingleton(ReleaseLevel Level);
	virtual ~ISingleton();

	// Singleton Manager에 객체 등록
	void										Attach();

private:
	friend class SingletonManager;
	// 삭제 레벨 얻어 오기
	ReleaseLevel								GetLevel()						{return m_Level;}

public:
	// 삭제 레벨
	ReleaseLevel								m_Level;
};
}//namespace Ane
