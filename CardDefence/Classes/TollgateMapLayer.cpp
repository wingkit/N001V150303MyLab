#include "TollgateMapLayer.h"
#include "SimpleAudioEngine.h"
#include "HeroManager.h"
#include "MonsterManager.h"
#include "Monster.h"
#include "MonsterPos.h"
#include "GlobalDefine.h"
#include "GlobalClient.h"

#define HOME_LAYER_LVL 3 // ���ݵĲ��
#define HERO_LAYER_LVL 10 // Ӣ�۵Ĳ��
#define MONSTER_LAYER_LVL 15 // ����Ĳ��
#define BULLET_LAYER_LVL 20 // �ӵ��Ĳ��

TollgateMapLayer::TollgateMapLayer(){
	m_iCurLevel = GlobalClient::getInstance()->getiCurTollgateLevel();
}

TollgateMapLayer::~TollgateMapLayer(){

}

bool TollgateMapLayer::init(){
	if (!Layer::init()){
		return false;
	}

	// ��ȡ�ؿ�����
	loadConfig();

	// ����Ӣ�۹�����
	m_heroMgr = HeroManager::createWithLevel(m_iCurLevel);
	this->addChild(m_heroMgr, HERO_LAYER_LVL);

	// �������������
	m_monsterMgr = MonsterManager::createWithLevel(m_iCurLevel);
	this->addChild(m_monsterMgr, MONSTER_LAYER_LVL);

	// ������ʼ��
	createStartPoint();

	// �����յ�
	createEndPoint();

	this->schedule(schedule_selector(TollgateMapLayer::logic));
	return true;
}

void TollgateMapLayer::initData(){
	// ��ʼ�����ꡢ�����ħ������
	int iTowerSoulNum = 50;
	int iMonsterNum = m_monsterMgr->getNotShowMonsterCount(); // ��������
	int iMagicNum = 500; // ħ������

	NOTIFY->postNotification("TowerSoulChange", (Ref*)iTowerSoulNum);
	NOTIFY->postNotification("MonsterNumChange", (Ref*)iMonsterNum);
	NOTIFY->postNotification("MagicChange", (Ref*)iMagicNum);
}

void TollgateMapLayer::loadConfig(){
	Size visibleSize = Director::getInstance()->getVisibleSize();

	// ��ӱ�������
	CocosDenshion::SimpleAudioEngine::getInstance()->playBackgroundMusic(
		StringUtils::format("music/tollgate_%d.mp3", m_iCurLevel).c_str(), true);

	// ��ӵ�ͼ����
	std::string sBG = StringUtils::format("tollgate/level_%d.jpg", m_iCurLevel);
	Sprite* map = Sprite::create(sBG.c_str());
	map->setPosition(Point(visibleSize.width / 2, visibleSize.height / 2));
	this->addChild(map, 1);
}

void TollgateMapLayer::logic(float dt){
	// Ӣ�۲�ͣ����Ƿ��ܴﵽ������Χ
	m_heroMgr->logic(dt, m_monsterMgr->getMonsterList());
}

void TollgateMapLayer::createEndPoint(){
	MonsterPos* pos = m_monsterMgr->getMonsterEndPos();

	Sprite* home = Sprite::create("sprite/end.png");
	home->setPosition(pos->getPos());
	home->setOpacity(150);

	auto rotateBy = RotateBy::create(15.0f, 360, 360);
	auto repeat = RepeatForever::create(rotateBy);
	home->runAction(repeat);
	this->addChild(home, HOME_LAYER_LVL);
}

void TollgateMapLayer::createStartPoint(){
	MonsterPos* pos = m_monsterMgr->getMonsterStartPos();

	Sprite* startSp = CCSprite::create("sprite/start.png");
	startSp->setPosition(pos->getPos());
	startSp->setOpacity(150);

	auto* rotateBy = RotateBy::create(15.0f, 360, 360);
	auto* repeat = RepeatForever::create(rotateBy);
	startSp->runAction(repeat);

	this->addChild(startSp, HOME_LAYER_LVL);
}