#pragma once

namespace Ane
{
// ���� ���� 
// ���μ����� ���� �ɶ� RELEASE_LEVEL_1, RELEASE_LEVEL_2, RELEASE_LEVEL_3 ������� ������
enum ReleaseLevel
{
	RELEASE_LEVEL_0 = 0,		// ���� : ���� 0�϶��� �Ҹ� ������ ���������� ����
	RELEASE_LEVEL_1 = 1,
	RELEASE_LEVEL_2 = 2,
	RELEASE_LEVEL_3 = 3,		
	// TODO : ���� 5�������� ���� IOCP�� TIMER������� �����ϰ� �������� ���� �ɼ� �ְ� �߰�
};

class ISingleton
{
public:	
	ISingleton(ReleaseLevel Level);
	virtual ~ISingleton();

	// Singleton Manager�� ��ü ���
	void										Attach();

private:
	friend class SingletonManager;
	// ���� ���� ��� ����
	ReleaseLevel								GetLevel()						{return m_Level;}

public:
	// ���� ����
	ReleaseLevel								m_Level;
};
}//namespace Ane
