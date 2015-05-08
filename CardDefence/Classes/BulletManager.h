/*
	描述： 子弹管理器

*/

#ifndef _BulletManager_H_
#define _BulletManager_H_
#include "cocos2d.h"
USING_NS_CC;
<<<<<<< HEAD
#define BULLET_MAX_CACHE_NUM 3 // 子弹缓存最大数量
=======
#define BULLET_MAX_CACHE_NUM 10 // 子弹缓存最大数量
>>>>>>> 242d9fd9e2218bb56c21948853acb0e3a3cae294
class BulletBase;
class BulletManager : public Node{
public:
	BulletManager();
	~BulletManager();
	static BulletManager* create();
	bool init();

	//  从缓存中获取一个未被使用的子弹
	BulletBase* getAnyUnUsedBullet();
private:
	// 子弹列表
	Vector<BulletBase*> m_bulletList;

	// 创建缓存子弹
	void createBullets();

	// 子弹逻辑
	void bulletLogicCheck(float dt);
};
#endif
