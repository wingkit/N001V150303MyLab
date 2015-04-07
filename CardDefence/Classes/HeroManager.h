/*
	������ Ӣ�۹�����

*/

#ifndef _HeroManager_H_
#define _HeroManager_H_
#include "cocos2d.h"
USING_NS_CC;

#define TOWER_POS_LAYER_LVL 5 // ������Ĳ��
#define TOWER_BORDER_LAYER_LVL 8 // ��̨�Ĳ��
#define TOWER_LAYER_LVL 10 // ���Ĳ��

class PosBase;
class TowerBorder;
class Monster;
class HeroManager : public Node{
public:
	HeroManager();
	~HeroManager();
	static HeroManager* createWithLevel(int iCurLevel); // ���ݵ�ǰ�㼶����Ӣ�۹�����
	bool initWithLevel(int iCurLevel);

	void logic(float dt, Vector<Monster*> monsterList);
private:
	// ������������������
	Vector<PosBase*> m_towerPosList;

	// ���������̨����
	Vector<TowerBorder*> m_towerBorderList;

	// ������̨
	void createTowerBorder(int iCurLevel);

	// �������꣬�������������
	void createTowerPos(Point pos);

	// �ҵ�����������̨����
	TowerBorder* findClickTowerBorder(Point pos);
};
#endif