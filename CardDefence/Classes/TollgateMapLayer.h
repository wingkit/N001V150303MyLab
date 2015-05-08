/*
	描述： 关卡地图图层

*/

#ifndef _TollgateMapLayer_H_
#define _TollgateMapLayer_H_
#include "cocos2d.h"
USING_NS_CC;

class HeroManager;
class MonsterManager;
class TollgateMapLayer : public Layer{
public:
	TollgateMapLayer();
	~TollgateMapLayer();

	CREATE_FUNC(TollgateMapLayer);
	virtual bool init();
<<<<<<< HEAD
	void initData();
private:
	// 当前关卡
	int m_iCurLevel;
	// 英雄管理器
	HeroManager* m_heroMgr;
	// 怪物管理器
=======
private:
	// 当前关卡
	int m_iCurLevel;
	HeroManager* m_heroMgr;
>>>>>>> 242d9fd9e2218bb56c21948853acb0e3a3cae294
	MonsterManager* m_monsterMgr;

	// 读取关卡配置
	void loadConfig();

	void logic(float dt);
<<<<<<< HEAD
	// 创建结束门
	void createEndPoint();
	// 创建开始门
=======

	void createEndPoint();
>>>>>>> 242d9fd9e2218bb56c21948853acb0e3a3cae294
	void createStartPoint();
};
#endif