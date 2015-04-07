/*
	������ �ӵ�������

*/

#ifndef _BulletManager_H_
#define _BulletManager_H_
#include "cocos2d.h"
USING_NS_CC;
#define BULLET_MAX_CACHE_NUM 10 // �ӵ������������
class BulletBase;
class BulletManager : public Node{
public:
	BulletManager();
	~BulletManager();
	static BulletManager* create();
	bool init();

	//  �ӻ����л�ȡһ��δ��ʹ�õ��ӵ�
	BulletBase* getAnyUnUsedBullet();
private:
	// �ӵ��б�
	Vector<BulletBase*> m_bulletList;

	// ���������ӵ�
	void createBullets();

	// �ӵ��߼�
	void bulletLogicCheck(float dt);
};
#endif
