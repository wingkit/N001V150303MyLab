#include "TowerPosEditorLayer.h"
#include "TowerPos.h"
#include "MonsterPos.h"
#include "PosLoadUtil.h"
TowerPosEditorLayer::TowerPosEditorLayer(){
	m_iCurLevel = 1;
	m_enMode = enMonsterPos;
}

TowerPosEditorLayer::~TowerPosEditorLayer(){

}

// ��ʼ��
bool TowerPosEditorLayer::init(){
	if (!Layer::init()) return false;

	// ���������¼�
	auto listener = EventListenerTouchOneByOne::create();
	listener->onTouchBegan = [] (Touch* touch, Event* event){
		return true;
	};
	listener->onTouchEnded = [&](Touch* touch, Event* event){
		Point pos = Director::getInstance()->convertToGL(touch->getLocationInView());
		// �жϵ�ǰ�༭����ģʽ�� ���в�ͬ�Ĳ���
		switch(m_enMode){
		case enTowerPos:
			editTowerPos(pos);
			break;
		case enMonsterPos:
			editMonsterPos(pos);
			break;
		}
	};
	_eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);

	// ��ȡ�����ļ�
	loadConfigFile();
	return true;
}

// ����һ�����������Ѿ����ھ�ɾ����
void TowerPosEditorLayer::editTowerPos(Point pos){
	// ����������Ѿ����ڵ������������ ��ɾ����������� ���򴴽����������
	PosBase* existPos = findExistTowerPos(pos);

	if (existPos != NULL) {
		deleteTowerPos(existPos);
	}else {
		createTowerPos(pos);
	}

}

// �������Ƿ����
PosBase* TowerPosEditorLayer::findExistTowerPos(Point pos){
	for (auto basePos : m_towerPosList){
		if (basePos->isClickMe(pos)){
			return basePos;
		}
	}
	return NULL;
}

void TowerPosEditorLayer::createTowerPos(Point pos){
	TowerPos* tPos = TowerPos::create(pos, true);
	this->addChild(tPos, 10);
	m_towerPosList.pushBack(tPos);
}

void TowerPosEditorLayer::deleteTowerPos(PosBase* existPos){
	this->removeChild(existPos);
	m_towerPosList.eraseObject(existPos);
}

void TowerPosEditorLayer::deleteAllPos(){
	this->removeAllChildrenWithCleanup(true);
	m_towerPosList.clear();
	m_monsterPosList.clear();
}

void TowerPosEditorLayer::outputPosToPlistFile(){
	// �����̨���������ļ�
	std::string sTowerPosPath = StringUtils::format("tollgate/towerPos_level_%d.plist", m_iCurLevel);
	outputPosToPlistFile(m_towerPosList, sTowerPosPath.c_str());
	// ����������������ļ�
	std::string sMonsterPosPath = StringUtils::format("tollgate/monsterPos_level_%d.plist", m_iCurLevel);
	outputPosToPlistFile(m_monsterPosList, sMonsterPosPath.c_str());
}

void TowerPosEditorLayer::outputPosToPlistFile(Vector<PosBase*> posList, const char* sFilePath){
	ValueMap fileDataMap;
	// ��������
	int index = 1;
	for (auto posBase : posList){
		ValueMap data;
		data["x"] = posBase->getPos().x;
		data["y"] = posBase->getPos().y;

		fileDataMap[StringUtils::toString(index)] = Value(data);

		index++;
	}
	FileUtils::getInstance()->writeToFile(fileDataMap, sFilePath);
}

void TowerPosEditorLayer::loadConfigFile(){
	Size visibleSize = Director::getInstance()->getVisibleSize();

	// ��ӵ�ͼ����
	std::string sBG = StringUtils::format("tollgate/level_%d.jpg", m_iCurLevel%3?m_iCurLevel%3:3);
	Sprite* map = Sprite::create(sBG.c_str());
	map->setPosition(Point(visibleSize.width/2, visibleSize.height/2));
	this->addChild(map, 1);
	// �������������
	std::string sTowerPosPath = StringUtils::format("tollgate/towerPos_level_%d.plist", m_iCurLevel);
	Vector<PosBase*> posList = PosLoadUtil::getInstance()->loadPosWithFile(sTowerPosPath.c_str(), enTowerPos, this, 10, true);
	// ���ع����������
	std::string sMonsterPosPath = StringUtils::format("tollgate/monsterPos_level_%d.plist", m_iCurLevel);
	posList = PosLoadUtil::getInstance()->loadPosWithFile(sMonsterPosPath.c_str(), enMonsterPos, this, 10, true);
	m_monsterPosList.pushBack(posList);
}

void TowerPosEditorLayer::editMonsterPos(Point pos){
	// ����������Ѿ����ڵĹ���������� ��ɾ���ö��󣬷��򴴽����������
	PosBase* existPos = findExistMonsterPos(pos);
	if (existPos != NULL){
		deleteMonsterPos(existPos);
	} else {
		createMonsterPos(pos);
	}
}

PosBase* TowerPosEditorLayer::findExistMonsterPos(Point pos){
	for (auto basePos : m_monsterPosList){
		if (basePos->isClickMe(pos)){
			return basePos;
		}
	}

	return NULL;
}

// �����������ӹ���
void TowerPosEditorLayer::createMonsterPos(Point pos){
	MonsterPos* mPos = MonsterPos::create(pos, true);
	this->addChild(mPos, 10);
	m_monsterPosList.pushBack(mPos);
}
// ��������ɾ����Ӧ����
void TowerPosEditorLayer::deleteMonsterPos(PosBase* existPos){
	this->removeChild(existPos);
	m_monsterPosList.eraseObject(existPos);
}

// �ı��������ͣ������������
void TowerPosEditorLayer::changeMode(){
	if (m_enMode == enMonsterPos){
		m_enMode = enTowerPos;
	} else {
		m_enMode = enMonsterPos;
	}
}

// ������ж����ٿ���һ��
int TowerPosEditorLayer::nextLvl(){
	// ɾ����ǰ���е��������
	deleteAllPos();
	// �ؿ�������1
	m_iCurLevel++;
	// ���¶�ȡ�����ļ�
	loadConfigFile();
	return m_iCurLevel;
}

// ������ж��󣬻�ȡ��һ������
int TowerPosEditorLayer::preLvl(){
	// ɾ����ǰ���е��������
	deleteAllPos();
	// �ؿ�������1
	m_iCurLevel--;
	// ���¶�ȡ�����ļ�
	loadConfigFile();
	return m_iCurLevel;
}

Vector<PosBase*> TowerPosEditorLayer::getMonsterPosList(){
	return m_monsterPosList;
}