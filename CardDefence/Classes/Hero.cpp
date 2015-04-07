#include "Hero.h"
#include "CsvUtil.h"
#include "GlobalPath.h"
#include "EnumHeroPropConfType.h"
#include "TollgateMapLayer.h"
#include "TollgateScene.h"
#include "Monster.h"
#include "BulletManager.h"
#include "BulletBase.h"

Hero::Hero(){
	m_atkMonster = NULL;
	m_isAtkCoolDown = false;
}

Hero::~Hero(){

}

Hero* Hero::create(Sprite* sprite){
	Hero* hero = new Hero();
	if (hero && hero->init(sprite)){
		hero->autorelease();
	} else {
		CC_SAFE_DELETE(hero);
	}
	return hero;
}

bool Hero::init(Sprite* sprite){
	bool bRet = false;
	do 
	{
		CC_BREAK_IF(!sprite);
		bindSprite(sprite);

		// 创建子弹管理器
		m_bulletMgr = BulletManager::create();
		this->addChild(m_bulletMgr);
		bRet = true;
	} while (0);

	return bRet;
}

Hero* Hero::createFromCsvFileByID(int iHeroID){
	Hero* hero = new Hero();
	if (hero && hero->initFromCsvFileByID(iHeroID)){
		hero->autorelease();
	} else {
		CC_SAFE_DELETE(hero);
	}
	return hero;
}

bool Hero::initFromCsvFileByID(int iHeroID){
	bool bRet = false;
	do 
	{
		CsvUtil* csvUtil = CsvUtil::getInstance();
		std::string sHeroID = StringUtils::toString(iHeroID);

		// 寻找ID所在的行
		int iLine = csvUtil->findValueInWithLine(sHeroID.c_str(), enHeroPropConf_ID, PATH_CSV_HERO_CONF);
		CC_BREAK_IF(iLine < 0);

		setID(iHeroID);
		setiModelID(csvUtil->getInt(iLine, enHeroPropConf_ModelId, PATH_CSV_HERO_CONF));
		setiBaseAtk(csvUtil->getInt(iLine, enHeroPropConf_BaseAtk, PATH_CSV_HERO_CONF));
		setiCurAtk(getiBaseAtk());
		setiAtkSpeed(csvUtil->getInt(iLine, enHeroPropConf_AtkSpeed, PATH_CSV_HERO_CONF));
		setiAtkRange(csvUtil->getInt(iLine, enHeroPropConf_AtkRange, PATH_CSV_HERO_CONF));
		setiUpgradeCostBase(csvUtil->getInt(iLine, enHeroPropConf_UpgradeCostBase, PATH_CSV_HERO_CONF));
		setfUpgradeAtkBase(csvUtil->getFloat(iLine, enHeroPropConf_UpgradeAtkbase, PATH_CSV_HERO_CONF));

		Sprite* sprite = Sprite::create(StringUtils::format("sprite/hero/hero_%d.png", iHeroID).c_str());
		CC_BREAK_IF(!sprite);

		CC_BREAK_IF(!init(sprite));
		bRet = true;
	} while (0);

	return bRet;
}

void Hero::checkAtkMonster(float ft, Vector<Monster*> monsterList){
	if (m_atkMonster != NULL){
		// 怪物已死亡
		if (m_atkMonster->isDead()){
			// 从怪物列表中删除怪物
			monsterList.eraseObject(m_atkMonster);

			// 清楚锁定的怪物引用
			m_atkMonster = NULL;
			return;
		}
		// 攻击冷却结束，可以攻击
		if (m_isAtkCoolDown == false){
			atk();
		}

		// 判断怪物是否离开攻击范围
		checkAimIsOutOfRange(monsterList);
	} else {
		// 选择一个进入攻击范围的怪物
		chooseAim(monsterList);
	}
}

void Hero::chooseAim(Vector<Monster*> monsterList){
	for (auto monster : monsterList){
		if (monster->isVisible() && isInAtkRange(monster->getPosition())){
			chooseAtkMonster(monster);
			log("InAtkRange!!!");
			break;
		}
	}
}

bool Hero::isInAtkRange(Point pos){
	int iDoubleAtkRange = getiAtkRange(); // 攻击范围
	Point heroPos = getPosition();

	float length = pos.getDistanceSq(heroPos);
	if (length <= iDoubleAtkRange * iDoubleAtkRange){
		return true;
	}
	return false;
}

void Hero::chooseAtkMonster(Monster* monster){
	m_atkMonster = monster;
}

void Hero::atk(){
	// 从子弹管理器中取出一个未被使用的子弹对象
	BulletBase* bullet = m_bulletMgr->getAnyUnUsedBullet();
	if (bullet != NULL){
		// 根据英雄情况设置子弹属性，锁定攻击目标
		Point heroWorldPos = this->getParent()->convertToWorldSpace(getPosition());
		bullet->setPosition(bullet->getParent()->convertToNodeSpace(heroWorldPos));
		bullet->setiAtkValue(getiCurAtk());
		bullet->lockAim(m_atkMonster);

		// 标记攻击冷却
		m_isAtkCoolDown = true;

		// 英雄攻击有间隔时间指若干秒后恢复攻击
		this->scheduleOnce(schedule_selector(Hero::atkCollDownEnd), getiAtkSpeed() /1000.0f);
	}
}

void Hero::atkCollDownEnd(float dt){
	m_isAtkCoolDown = false;
}

void Hero::checkAimIsOutOfRange(Vector<Monster*> monsterList){
	if (m_atkMonster != NULL){
		if (isInAtkRange(m_atkMonster->getPosition()) == false){
			missAtkMonster();
		}
	}
}

void Hero::missAtkMonster(){
	log("Out of Range");
	m_atkMonster = NULL;
}

void Hero::upgrade(){
	Sprite* sprite = getSprite();
	if (sprite == NULL || m_iLevel >= 4){
		return ;
	}
	// 增加等级
	m_iLevel++;

	// 英雄等级特效
	if (m_iLevel == 2){
		Sprite* heroTop1 = Sprite::create("sprite/hero/hero_top_1.png");
		this->addChild(heroTop1);
	}

	if (m_iLevel == 3){
		Sprite* heroTop2 = Sprite::create("sprite/hero/hero_top_2.png");
		this->addChild(heroTop2);

		auto rotateBy = RotateBy::create(25.0f, 360, 360);
		auto repeat = RepeatForever::create(rotateBy);
		heroTop2->runAction(repeat);
	}
	if (m_iLevel == 4){
		Sprite* heroTop3 = Sprite::create("sprite/hero/hero_top_3.png");
		this->addChild(heroTop3);

		auto rotateBy = RotateBy::create(10.0f, 360, 360);
		auto repeat = RepeatForever::create(rotateBy);
		heroTop3->runAction(repeat);
	}
	// 增加英雄攻击力
	setiBaseAtk(getiBaseAtk() * m_fUpgradeAtkBase);
	setiCurAtk(getiBaseAtk());
}