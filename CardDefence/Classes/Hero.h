/*
	������ Ӣ�ۣ�������
*/

#ifndef _Hero_H_
#define _Hero_H_
#include "Entity.h"

class Monster;
class BulletManager;
class Hero : public Entity{
public:
	Hero();
	~Hero();

	static Hero* create(Sprite* sprite);
	bool init(Sprite* sprite);

	// ����Ӣ��ID�� �������ļ��ж�ȡӢ������
	static Hero* createFromCsvFileByID(int iHeroID);
	bool initFromCsvFileByID(int iHeroID);

	CC_SYNTHESIZE(int, m_iBaseAtk, iBaseAtk); // ����������
	CC_SYNTHESIZE(int, m_iCurAtk, iCurAtk); // ��ǰ������
	CC_SYNTHESIZE(int, m_iAtkSpeed, iAtkSpeed); // �����������λ������)
	CC_SYNTHESIZE(int, m_iAtkRange, iAtkRange); // ������Χ���뾶��
	CC_SYNTHESIZE(int, m_iUpgradeConstBase, iUpgradeCostBase); // �������Ļ���ֵ
	CC_SYNTHESIZE(float, m_fUpgradeAtkBase, fUpgradeAtkBase); // ���������ӳ�ϵ��

	// ����Ӣ��
	void upgrade();

<<<<<<< HEAD
	// ɨ����Թ����Ĺ���
=======
>>>>>>> 242d9fd9e2218bb56c21948853acb0e3a3cae294
	void checkAtkMonster(float ft, Vector<Monster*> monsterList);

private:
	// �����Ƿ���ȴ
	bool m_isAtkCoolDown;

	// ��ǰ�����Ĺ���
	Monster* m_atkMonster;

	// �ӵ�������
	BulletManager* m_bulletMgr;

	// ��Ⲣѡ����빥����Χ�Ĺ�� ���߹����ѽ��뷶Χ�Ĺ���
	void checkAtkMonster(float ft);
<<<<<<< HEAD
	// ����Ŀ��
	void chooseAim(Vector<Monster*> monsterList);
	// 
	void chooseAtkMonster(Monster* monster);
	// 
	bool isInAtkRange(Point pos);
	// ����
	void atk();

	void atkCollDownEnd(float dt);

	void checkAimIsOutOfRange(Vector<Monster*> monsterList);
	//
=======

	void chooseAim(Vector<Monster*> monsterList);
	void chooseAtkMonster(Monster* monster);
	bool isInAtkRange(Point pos);

	void atk();
	void atkCollDownEnd(float dt);

	void checkAimIsOutOfRange(Vector<Monster*> monsterList);
>>>>>>> 242d9fd9e2218bb56c21948853acb0e3a3cae294
	void missAtkMonster();
};
#endif