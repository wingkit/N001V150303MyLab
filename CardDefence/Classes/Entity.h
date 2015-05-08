/*
	描述： 实体基类
*/

#ifndef _Entity_H_
#define _Entity_H_
#include "cocos2d.h"
USING_NS_CC;

class Entity : public Node{
public:
	Entity();
	~Entity();
<<<<<<< HEAD
	// 绑定当前的精灵
	void bindSprite(Sprite* sprite);

=======

	void bindSprite(Sprite* sprite);
>>>>>>> 242d9fd9e2218bb56c21948853acb0e3a3cae294
	Sprite* getSprite();

	void hurtMe(int iHurtValue); // 被攻击
	bool isDead(); // 是否死亡

protected:
	virtual void onDead(); // 实体死亡时调用
	virtual void onBindSprite(); // 绑定精灵对象时调用
	virtual void onHurt(int iHurtValue); // 受伤害时调用

private:
	Sprite* m_sprite;

	CC_SYNTHESIZE(int, m_ID, ID); // 实体ID
	CC_SYNTHESIZE(int, m_iModelID, iModelID); // 模型ID(资源ID)
	CC_SYNTHESIZE(std::string, m_sName, sName); // 名字
	CC_SYNTHESIZE(int, m_iHP, iHP); // HP
	CC_SYNTHESIZE(int, m_iDefense, iDefense); // 防御
	CC_SYNTHESIZE(int, m_iSpeed, iSpeed); // 移动速度
	CC_SYNTHESIZE(int, m_iLevel, iLevel); // 等级
	bool m_isDead;
};
#endif