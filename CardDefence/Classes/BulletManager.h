/*
	������ �ӵ�������

*/

#ifndef _BulletManager_H_
#define _BulletManager_H_
#include "cocos2d.h"
USING_NS_CC;
<<<<<<< HEAD
#define BULLET_MAX_CACHE_NUM 3 // �ӵ������������
=======
#define BULLET_MAX_CACHE_NUM 10 // �ӵ������������
>>>>>>> 242d9fd9e2218bb56c21948853acb0e3a3cae294
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
