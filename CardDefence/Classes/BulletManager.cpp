#include "BulletManager.h"
#include "BulletBase.h"
#include "BulletNormal.h"
<<<<<<< HEAD
#include "BulletArrow.h"
=======

>>>>>>> 242d9fd9e2218bb56c21948853acb0e3a3cae294
BulletManager::BulletManager(){

}

BulletManager::~BulletManager(){

}

BulletManager* BulletManager::create(){
	BulletManager* bulletMgr = new BulletManager();

	if (bulletMgr && bulletMgr->init()){
		bulletMgr->autorelease();
	} else {
		CC_SAFE_DELETE(bulletMgr);
	}

	return bulletMgr;
}

bool BulletManager::init(){
	// �����ӵ�����
	createBullets();

	// ѭ������ӵ��߼�
	this->schedule(schedule_selector(BulletManager::bulletLogicCheck));

	return true;
}

void BulletManager::createBullets(){
	BulletBase* bullet = NULL;
<<<<<<< HEAD

	for (int i = 0; i < BULLET_MAX_CACHE_NUM / 2; i++){
		bullet = BulletNormal::create();
		bullet->setUsed(false);
		m_bulletList.pushBack(bullet);
		this->addChild(bullet);
	}

	for (int i = 0; i < BULLET_MAX_CACHE_NUM / 2; i++){
		bullet = BulletArrow::create();
=======
	for (int i = 0; i < BULLET_MAX_CACHE_NUM; i++){
		bullet = BulletNormal::create();

>>>>>>> 242d9fd9e2218bb56c21948853acb0e3a3cae294
		bullet->setUsed(false);
		m_bulletList.pushBack(bullet);
		this->addChild(bullet);
	}
<<<<<<< HEAD

=======
>>>>>>> 242d9fd9e2218bb56c21948853acb0e3a3cae294
}

void BulletManager::bulletLogicCheck(float dt){
	for (auto bullet : m_bulletList){
		if (bullet->isUsed()){
<<<<<<< HEAD
			// ��ȡ��ǰ�ӵ����󶨵Ĺ���
			auto aim = bullet->getAim();
			// �ж�Ŀ������Ƿ����
=======
			auto aim = bullet->getAim();

>>>>>>> 242d9fd9e2218bb56c21948853acb0e3a3cae294
			if (aim != NULL){
				// �ж��ӵ��Ƿ�ﵽ��Ŀ������ǵĻ����˺�Ŀ�꣨ʹ��MoveTo��
				if(bullet->isArrive()){
					aim->hurtMe(bullet->getiAtkValue());

					// �ӵ�����Ŀ�������Ϊδʹ��״̬
					bullet->setUsed(false);
				}
			}
		}
	}
}

BulletBase* BulletManager::getAnyUnUsedBullet(){
	for (auto bullet : m_bulletList){
		if (bullet->isUsed() == false){
			bullet->setUsed(true);
			return bullet;
		}
	}

	return NULL;
}