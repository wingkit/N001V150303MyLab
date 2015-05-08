/*
	������ �������
*/

#ifndef _Monster_H_
#define _Monster_H_
#include "editor-support/cocostudio/CCSGUIReader.h"
<<<<<<< HEAD
#include "extensions/cocos-ext.h"
=======
#include "cocos-ext.h"
>>>>>>> 242d9fd9e2218bb56c21948853acb0e3a3cae294
#include "ui/CocosGUI.h"
using namespace cocos2d::ui;
using namespace cocostudio;
USING_NS_CC_EXT;
#include "Entity.h"
<<<<<<< HEAD
#include "GlobalDefine.h"
=======
>>>>>>> 242d9fd9e2218bb56c21948853acb0e3a3cae294
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
<<<<<<< HEAD
	CC_SYNTHESIZE_BOOL(m_isMoveEnd, MoveEnd); // �Ƿ񵽴�Ŀ�ĵ�
=======
>>>>>>> 242d9fd9e2218bb56c21948853acb0e3a3cae294
};

#endif