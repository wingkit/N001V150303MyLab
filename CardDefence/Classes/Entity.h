/*
	������ ʵ�����
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
	// �󶨵�ǰ�ľ���
	void bindSprite(Sprite* sprite);

=======

	void bindSprite(Sprite* sprite);
>>>>>>> 242d9fd9e2218bb56c21948853acb0e3a3cae294
	Sprite* getSprite();

	void hurtMe(int iHurtValue); // ������
	bool isDead(); // �Ƿ�����

protected:
	virtual void onDead(); // ʵ������ʱ����
	virtual void onBindSprite(); // �󶨾������ʱ����
	virtual void onHurt(int iHurtValue); // ���˺�ʱ����

private:
	Sprite* m_sprite;

	CC_SYNTHESIZE(int, m_ID, ID); // ʵ��ID
	CC_SYNTHESIZE(int, m_iModelID, iModelID); // ģ��ID(��ԴID)
	CC_SYNTHESIZE(std::string, m_sName, sName); // ����
	CC_SYNTHESIZE(int, m_iHP, iHP); // HP
	CC_SYNTHESIZE(int, m_iDefense, iDefense); // ����
	CC_SYNTHESIZE(int, m_iSpeed, iSpeed); // �ƶ��ٶ�
	CC_SYNTHESIZE(int, m_iLevel, iLevel); // �ȼ�
	bool m_isDead;
};
#endif