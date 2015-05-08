/*
	描述： 怪物基类
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

	// 给定怪物ID，从配置文件中读取怪物数据
	static Monster* createFromCsvFileByID(int iMonsterID);
	bool initFromCsvFileByID(int iMonsterID);

protected:
	virtual void onDead() override;
	virtual void onBindSprite() override;
	virtual void onHurt(int iHurtValue) override;

public:
	// 按照给定的坐标点移动
	void moveByPosList(Vector<PosBase*> posList);
private:
	ControllerSimpleMove* m_moveController; // 移动控制器
	LoadingBar* m_hpBar;
	int m_iMaxHP;

	CC_SYNTHESIZE(int, m_iLevel, iLevel); // 等级
	CC_SYNTHESIZE(float, m_fShowTime, fShowTime); // 出场间隔：秒
<<<<<<< HEAD
	CC_SYNTHESIZE_BOOL(m_isMoveEnd, MoveEnd); // 是否到达目的地
=======
>>>>>>> 242d9fd9e2218bb56c21948853acb0e3a3cae294
};

#endif