#include "HeroManager.h"
#include "PosLoadUtil.h"
#include "PosBase.h"
#include "TowerPos.h"
#include "TowerBorder.h"
#include "Hero.h"
#include "Monster.h"

HeroManager::HeroManager(){

}

HeroManager::~HeroManager(){

}

HeroManager* HeroManager::createWithLevel(int iCurLevel){
	HeroManager* heroMgr = new HeroManager();
	if (heroMgr && heroMgr->initWithLevel(iCurLevel)){
		heroMgr->autorelease();
	} else {
		CC_SAFE_DELETE(heroMgr);
	}
	return heroMgr;
}

bool HeroManager::initWithLevel(int iCurLevel){
	// 加载塔坐标对象
<<<<<<< HEAD
	Vector<PosBase*> posList = PosLoadUtil::getInstance()->loadPosWithJsonFile("towerPos", StringUtils::format("towerPos_level_%d.json", iCurLevel).c_str(), enTowerPos, this, 10, false);
	// 当没有用户自定义的json文件时，采用默认的plist文件
	if (posList.empty()){
		std::string sTowerPosPath = StringUtils::format("tollgate/towerPos_level_%d.plist", iCurLevel);
		posList = PosLoadUtil::getInstance()->loadPosWithFile(sTowerPosPath.c_str(), enTowerPos, this, 10, false);
		log("func[initWithLevel]: the vector posList is empty!");
	}
=======
	std::string sTowerPosPath = StringUtils::format("tollgate/towerPos_level_%d.plist", iCurLevel);
	Vector<PosBase*> posList = PosLoadUtil::getInstance()->loadPosWithFile(
		sTowerPosPath.c_str(), enTowerPos, this, 10, false);
>>>>>>> 242d9fd9e2218bb56c21948853acb0e3a3cae294
	m_towerPosList.pushBack(posList);

	// 创建炮台
	createTowerBorder(iCurLevel);

	// 添加触摸监听
	auto listener = EventListenerTouchOneByOne::create();

	listener->onTouchBegan = [](Touch* touch, Event* event){
		return true;
	};
	listener->onTouchEnded = [&](Touch* touch, Event* event){
		Point pos = Director::getInstance()->convertToGL(touch->getLocationInView());

		// 获取被单击的塔坐标
		TowerBorder* clickBorder = findClickTowerBorder(pos);

		if (clickBorder == NULL){
			return;
		}
		// 当前塔坐标没有英雄对象，则添加英雄
		if (clickBorder->getHero() == NULL){
			Hero* hero = Hero::createFromCsvFileByID(1);
<<<<<<< HEAD
			Size heroSize = hero->getContentSize();
			Point borderPos = clickBorder->getPosition();
			hero->setPosition(Point(borderPos.x, borderPos.y + heroSize.height/2));
=======
			hero->setPosition(clickBorder->getPosition());
>>>>>>> 242d9fd9e2218bb56c21948853acb0e3a3cae294
			this->addChild(hero, TOWER_LAYER_LVL);

			// 绑定英雄对象到炮台
			clickBorder->bindHero(hero);
		} else {
			clickBorder->showTowerOprBtns();
		}
	};
	_eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);
	return true;
}

void HeroManager::createTowerBorder(int iCurLevel){
	for (auto tPos : m_towerPosList){
		TowerBorder* border = TowerBorder::create();
		border->upgrade();
<<<<<<< HEAD
=======
		border->upgrade();
>>>>>>> 242d9fd9e2218bb56c21948853acb0e3a3cae294
		border->setPosition(tPos->getPos());
		this->addChild(border);

		m_towerBorderList.pushBack(border);
	}
}

void HeroManager::createTowerPos(Point pos){
<<<<<<< HEAD
	// 炮台框（正方形）
=======
>>>>>>> 242d9fd9e2218bb56c21948853acb0e3a3cae294
	TowerPos* tPos = TowerPos::create(pos, true);
	this->addChild(tPos, TOWER_POS_LAYER_LVL);
	m_towerPosList.pushBack(tPos);
}

TowerBorder* HeroManager::findClickTowerBorder(Point pos){
	for (auto tBorder : m_towerBorderList){
		if (tBorder->isClickMe(pos)){
			return tBorder;
		}
	}
	return NULL;
}

void HeroManager::logic(float dt, Vector<Monster*> monsterList){
<<<<<<< HEAD
	// 逐个怪物与英雄比较 看是否达到英雄的射击范围
=======
>>>>>>> 242d9fd9e2218bb56c21948853acb0e3a3cae294
	for (auto tBorder : m_towerBorderList){
		if (tBorder->getHero() != NULL){
			tBorder->getHero()->checkAtkMonster(dt, monsterList);
		}
	}
}