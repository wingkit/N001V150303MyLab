#include "TowerPosEditorLayer.h"
#include "TowerPos.h"
#include "MonsterPos.h"
#include "PosLoadUtil.h"
#include "json/document.h"
#include "json/writer.h"
#include "json/stringbuffer.h"


TowerPosEditorLayer::TowerPosEditorLayer(){
	m_iCurLevel = 0;
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

bool TowerPosEditorLayer::outputPosToPlistFile(){
	bool bRet = false;

	// �����̨���������ļ�
	std::string sTowerPosPath = StringUtils::format("tollgate/towerPos_level_%d.plist", m_iCurLevel);
	bRet = outputPosToPlistFile(m_towerPosList, sTowerPosPath.c_str());
	if(!bRet)log("output towerPos to plist failed!");

	// ����������������ļ�
	std::string sMonsterPosPath = StringUtils::format("tollgate/monsterPos_level_%d.plist", m_iCurLevel);
	bRet = outputPosToPlistFile(m_monsterPosList, sMonsterPosPath.c_str());
	if(!bRet)log("output monsterPos to plist failed!");

	// �����̨����json�����ļ�
	std::string sTowerPosPath2 = StringUtils::format("towerPos_level_%d.json", m_iCurLevel);
	bRet = outputPosToJsonFile("towerPos", m_towerPosList, sTowerPosPath2.c_str());
	if(!bRet)log("output towerPos to json failed!");

	// �����������json�����ļ�
	std::string sMonsterPosPath2 = StringUtils::format("monsterPos_level_%d.json", m_iCurLevel);
	bRet = outputPosToJsonFile("monsterPos", m_monsterPosList, sMonsterPosPath2.c_str());
	if(!bRet)log("output monsterPos to json failed!");

	return bRet;
}

bool TowerPosEditorLayer::outputPosToPlistFile(Vector<PosBase*> posList, const char* sFilePath){
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
	return FileUtils::getInstance()->writeToFile(fileDataMap, sFilePath);
}

bool TowerPosEditorLayer::outputPosToJsonFile(const char* key, Vector<PosBase*> posList, const char* sFilePath){
	// ����json�ļ����洢��getWritablePath�ļ�����
	rapidjson::Document writedoc;
	writedoc.SetObject();
	rapidjson::Document::AllocatorType& allocator = writedoc.GetAllocator();
	int index = 1;
	std::stringstream ss;
	rapidjson::Value map(rapidjson::kObjectType);
	std::vector<std::string*> vecStr;
	for (auto posBase : posList){
		rapidjson::Value data(rapidjson::kObjectType);
		data.AddMember("x", posBase->getPos().x, allocator);
		data.AddMember("y", posBase->getPos().y, allocator);
		std::string* key = new std::string(StringUtils::toString(index++));
		vecStr.push_back(key);
		map.AddMember(key->c_str(), data, allocator);
	}
	writedoc.AddMember(key, map, allocator);
	rapidjson::StringBuffer buffer;
	rapidjson::Writer<rapidjson::StringBuffer> writer(buffer);
	writedoc.Accept(writer);
	auto path = FileUtils::getInstance()->getWritablePath();
	path.append(sFilePath);
	FILE* file = fopen(path.c_str(), "wb");
	if (file){
		fputs(buffer.GetString(), file);
		fclose(file);
	}
	while(!vecStr.empty()){
		delete(vecStr.back());
		vecStr.pop_back();
	}
	CCLOG("%s", buffer.GetString());
	return true;
}

void TowerPosEditorLayer::loadConfigFile(){
	if (m_iCurLevel < 0) {
		m_iCurLevel = 0;
	} else if (m_iCurLevel > 2){
		m_iCurLevel = 2;
	}

	Size visibleSize = Director::getInstance()->getVisibleSize();

	// ��ӵ�ͼ����
	std::string sBG = StringUtils::format("tollgate/level_%d.jpg", m_iCurLevel);
	Sprite* map = Sprite::create(sBG.c_str());
	map->setPosition(Point(visibleSize.width/2, visibleSize.height/2));
	this->addChild(map, 1);

	Vector<PosBase*> posList;

	auto towerPos_path = FileUtils::getInstance()->getWritablePath();
	towerPos_path.append(StringUtils::format("towerPos_level_%d.json", m_iCurLevel));
	// ���json�ļ�����ʱ,ʹ��plist���ļ�
	if (!FileUtils::getInstance()->isFileExist(towerPos_path.c_str())) {
		log("The monsterPos_level_*.json file is missing, read the *.plist one instead .");
		// �������������
		std::string sTowerPosPath = StringUtils::format("tollgate/towerPos_level_%d.plist", m_iCurLevel);
		posList = PosLoadUtil::getInstance()->loadPosWithFile(sTowerPosPath.c_str(), enTowerPos, this, 10, true);
	} else {
		std::string sTowerPosPath = StringUtils::format("towerPos_level_%d.json", m_iCurLevel);
		posList = PosLoadUtil::getInstance()->loadPosWithJsonFile("towerPos",sTowerPosPath.c_str(), enTowerPos, this, 10, true);
	}
	m_towerPosList.pushBack(posList);


	auto monsterPos_path = FileUtils::getInstance()->getWritablePath();
	monsterPos_path.append(StringUtils::format("monsterPos_level_%d.json", m_iCurLevel));
	// ���json�ļ�����ʱ,ʹ��plist���ļ�
	if (!FileUtils::getInstance()->isFileExist(monsterPos_path.c_str())) {
		log("The monsterPos_level_*.json file is missing, read the *.plist one instead .");
		// ���ع����������
		std::string sMonsterPosPath = StringUtils::format("tollgate/monsterPos_level_%d.plist", m_iCurLevel);
		posList = PosLoadUtil::getInstance()->loadPosWithFile(sMonsterPosPath.c_str(), enMonsterPos, this, 10, true);
	} else {
		std::string sMonsterPosPath = StringUtils::format("monsterPos_level_%d.json", m_iCurLevel);
		posList = PosLoadUtil::getInstance()->loadPosWithJsonFile("monsterPos",sMonsterPosPath.c_str(), enMonsterPos, this, 10, true);
	}
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
EnumPosType TowerPosEditorLayer::changeMode(){
	if (m_enMode == enMonsterPos){
		m_enMode = enTowerPos;
	} else {
		m_enMode = enMonsterPos;
	}
	return m_enMode;
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