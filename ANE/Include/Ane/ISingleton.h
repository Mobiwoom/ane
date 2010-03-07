#pragma once

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
public:
	ISingleton(ReleaseLevel Level);
	virtual ~ISingleton();

	void										Attach();

private:
	friend class SingletonManager;
	ReleaseLevel								GetLevel()						{return m_Level;}

public:
	ReleaseLevel								m_Level;
	
};

}//namespace Ane
