#include "BulletManager.h"
#include "BulletBase.h"
#include "BulletNormal.h"
#include "BulletArrow.h"
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

	for (int i = 0; i < BULLET_MAX_CACHE_NUM / 2; i++){
		bullet = BulletNormal::create();
		bullet->setUsed(false);
		m_bulletList.pushBack(bullet);
		this->addChild(bullet);
	}

	for (int i = 0; i < BULLET_MAX_CACHE_NUM / 2; i++){
		bullet = BulletArrow::create();
		bullet->setUsed(false);
		m_bulletList.pushBack(bullet);
		this->addChild(bullet);
	}

}

void BulletManager::bulletLogicCheck(float dt){
	for (auto bullet : m_bulletList){
		if (bullet->isUsed()){
			// ��ȡ��ǰ�ӵ����󶨵Ĺ���
			auto aim = bullet->getAim();
			// �ж�Ŀ������Ƿ����
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