/*
	������ �������
*/

#ifndef _Monster_H_
#define _Monster_H_
#include "editor-support/cocostudio/CCSGUIReader.h"
#include "cocos-ext.h"
#include "ui/CocosGUI.h"
using namespace cocos2d::ui;
using namespace cocostudio;
USING_NS_CC_EXT;
#include "Entity.h"
#define MONSTER_SPEED_INIT 1

class ControllerSimpleMove;
class PosBase;
class Monster : public Entity{
public:
	Monster();
	~Monster();
	CREATE_FUNC(Monster);
	virtual bool init();

	// ��������ID���������ļ��ж�ȡ��������
	static Monster* createFromCsvFileByID(int iMonsterID);
	bool initFromCsvFileByID(int iMonsterID);

protected:
	virtual void onDead() override;
	virtual void onBindSprite() override;
	virtual void onHurt(int iHurtValue) override;

public:
	// ���ո�����������ƶ�
	void moveByPosList(Vector<PosBase*> posList);
private:
	ControllerSimpleMove* m_moveController; // �ƶ�������
	LoadingBar* m_hpBar;
	int m_iMaxHP;

	CC_SYNTHESIZE(int, m_iLevel, iLevel); // �ȼ�
	CC_SYNTHESIZE(float, m_fShowTime, fShowTime); // �����������
};

#endif