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
	// �������������
	Vector<PosBase*> posList = PosLoadUtil::getInstance()->loadPosWithJsonFile("towerPos", StringUtils::format("towerPos_level_%d.json", iCurLevel).c_str(), enTowerPos, this, 10, false);
	// ��û���û��Զ����json�ļ�ʱ������Ĭ�ϵ�plist�ļ�
	if (posList.empty()){
		std::string sTowerPosPath = StringUtils::format("tollgate/towerPos_level_%d.plist", iCurLevel);
		posList = PosLoadUtil::getInstance()->loadPosWithFile(sTowerPosPath.c_str(), enTowerPos, this, 10, false);
		log("func[initWithLevel]: the vector posList is empty!");
	}
	m_towerPosList.pushBack(posList);

	// ������̨
	createTowerBorder(iCurLevel);

	// ��Ӵ�������
	auto listener = EventListenerTouchOneByOne::create();

	listener->onTouchBegan = [](Touch* touch, Event* event){
		return true;
	};
	listener->onTouchEnded = [&](Touch* touch, Event* event){
		Point pos = Director::getInstance()->convertToGL(touch->getLocationInView());

		// ��ȡ��������������
		TowerBorder* clickBorder = findClickTowerBorder(pos);

		if (clickBorder == NULL){
			return;
		}
		// ��ǰ������û��Ӣ�۶��������Ӣ��
		if (clickBorder->getHero() == NULL){
			Hero* hero = Hero::createFromCsvFileByID(1);
			Size heroSize = hero->getContentSize();
			Point borderPos = clickBorder->getPosition();
			hero->setPosition(Point(borderPos.x, borderPos.y + heroSize.height/2));
			this->addChild(hero, TOWER_LAYER_LVL);

			// ��Ӣ�۶�����̨
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
		border->setPosition(tPos->getPos());
		this->addChild(border);

		m_towerBorderList.pushBack(border);
	}
}

void HeroManager::createTowerPos(Point pos){
	// ��̨�������Σ�
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
	// ���������Ӣ�۱Ƚ� ���Ƿ�ﵽӢ�۵������Χ
	for (auto tBorder : m_towerBorderList){
		if (tBorder->getHero() != NULL){
			tBorder->getHero()->checkAtkMonster(dt, monsterList);
		}
	}
}