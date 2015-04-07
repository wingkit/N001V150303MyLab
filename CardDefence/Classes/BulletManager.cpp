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
	// 创建子弹对象
	createBullets();

	// 循环检测子弹逻辑
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
			// 获取当前子弹所绑定的怪物
			auto aim = bullet->getAim();
			// 判断目标对象是否存在
			if (aim != NULL){
				// 判断子弹是否达到了目标出，是的话，伤害目标（使用MoveTo）
				if(bullet->isArrive()){
					aim->hurtMe(bullet->getiAtkValue());

					// 子弹攻击目标后，重置为未使用状态
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