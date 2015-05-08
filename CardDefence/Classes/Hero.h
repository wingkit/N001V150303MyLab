/*
	描述： 英雄（炮塔）
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

	// 给定英雄ID， 从配置文件中读取英雄数据
	static Hero* createFromCsvFileByID(int iHeroID);
	bool initFromCsvFileByID(int iHeroID);

	CC_SYNTHESIZE(int, m_iBaseAtk, iBaseAtk); // 基础攻击力
	CC_SYNTHESIZE(int, m_iCurAtk, iCurAtk); // 当前攻击力
	CC_SYNTHESIZE(int, m_iAtkSpeed, iAtkSpeed); // 攻击间隔（单位：毫秒)
	CC_SYNTHESIZE(int, m_iAtkRange, iAtkRange); // 攻击范围（半径）
	CC_SYNTHESIZE(int, m_iUpgradeConstBase, iUpgradeCostBase); // 升级消耗基础值
	CC_SYNTHESIZE(float, m_fUpgradeAtkBase, fUpgradeAtkBase); // 升级攻击加成系数

	// 升级英雄
	void upgrade();

<<<<<<< HEAD
	// 扫描可以攻击的怪物
=======
>>>>>>> 242d9fd9e2218bb56c21948853acb0e3a3cae294
	void checkAtkMonster(float ft, Vector<Monster*> monsterList);

private:
	// 攻击是否冷却
	bool m_isAtkCoolDown;

	// 当前锁定的怪物
	Monster* m_atkMonster;

	// 子弹管理类
	BulletManager* m_bulletMgr;

	// 检测并选择进入攻击范围的怪物， 或者攻击已进入范围的怪物
	void checkAtkMonster(float ft);
<<<<<<< HEAD
	// 锁定目标
	void chooseAim(Vector<Monster*> monsterList);
	// 
	void chooseAtkMonster(Monster* monster);
	// 
	bool isInAtkRange(Point pos);
	// 攻击
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