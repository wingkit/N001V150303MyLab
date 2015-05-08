#include "MonsterManager.h"
#include "EnumPosType.h"
#include "PosLoadUtil.h"
#include "Monster.h"
#include "PosBase.h"
#include "MonsterPos.h"
<<<<<<< HEAD
#include "GlobalDefine.h"
=======
>>>>>>> 242d9fd9e2218bb56c21948853acb0e3a3cae294

MonsterManager::MonsterManager(){
	m_fShowTimeCount = 0;
}

MonsterManager::~MonsterManager(){

}

MonsterManager* MonsterManager::createWithLevel(int iCurLevel){
	MonsterManager* monsterMgr = new MonsterManager();

	if (monsterMgr && monsterMgr->initWithLevel(iCurLevel)){
		monsterMgr->autorelease();
	} else {
		CC_SAFE_DELETE(monsterMgr);
	}

	return monsterMgr;
}

bool MonsterManager::initWithLevel(int iCurLevel){
	// ��������
	createMonsters(iCurLevel);
	return true;
}

int MonsterManager::getNotShowMonsterCount(){
	return m_notShowMonsterList.size();
}

Vector<Monster*> MonsterManager::getMonsterList(){
	return m_monsterList;
}

MonsterPos* MonsterManager::getMonsterStartPos(){
	return (MonsterPos*) m_monsterPosList.at(0);
}

MonsterPos* MonsterManager::getMonsterEndPos(){
	return (MonsterPos*)m_monsterPosList.at(m_monsterPosList.size() - 1);
}

void MonsterManager::createMonsters(int iCurLevel){
	// ���ع����������
<<<<<<< HEAD
	Vector<PosBase*> posList = PosLoadUtil::getInstance()->loadPosWithJsonFile("monsterPos", StringUtils::format("monsterPos_level_%d.json", iCurLevel).c_str(), enTowerPos, this, 10, false);
	// ��û���û��Զ����json�ļ�ʱ������Ĭ�ϵ�plist�ļ�
	if (posList.empty()){
		std::string sMonsterPosPath = StringUtils::format("tollgate/monsterPos_level_%d.plist", iCurLevel);
		posList = PosLoadUtil::getInstance()->loadPosWithFile(sMonsterPosPath.c_str(), enMonsterPos, this, 10, false);
		log("func[createMonsters]: the vector posList is empty!");
	}
=======
	std::string sMonsterPosPath = StringUtils::format("tollgate/monsterPos_level_%d.plist", iCurLevel);
	auto posList = PosLoadUtil::getInstance()->loadPosWithFile(sMonsterPosPath.c_str(), enMonsterPos, this, 10, false);
>>>>>>> 242d9fd9e2218bb56c21948853acb0e3a3cae294
	m_monsterPosList.pushBack(posList);

	// ��ȡ�����ļ�
	std::string sMonsterConfPath = StringUtils::format("tollgate/monster_level_%d.plist", iCurLevel);
	ValueMap fileDataMap = FileUtils::getInstance()->getValueMapFromFile(sMonsterConfPath.c_str());
<<<<<<< HEAD
	// ��������
=======

>>>>>>> 242d9fd9e2218bb56c21948853acb0e3a3cae294
	int size = fileDataMap.size();
	for (int i = 1; i <= size; i++){
		Value value = fileDataMap.at(StringUtils::toString(i));
		ValueMap data = value.asValueMap();
		// �ӹ�����������ļ���ȡ����ID�ͳ���ʱ�䣬�������й��ﵽδ�����б�
		int id = data["id"].asInt();
		float fShowTime = data["showTime"].asFloat();

		auto monster = Monster::createFromCsvFileByID(id);
<<<<<<< HEAD
		if (monster == NULL) {log("the monster is Null, read csv file fail!"); return;}
=======
>>>>>>> 242d9fd9e2218bb56c21948853acb0e3a3cae294
		monster->setfShowTime(fShowTime);
		monster->setVisible(false);

		// ���ù��ﾫ��
		std::string spPath = StringUtils::format("sprite/monster/monster_%d.png", monster->getiModelID());
		monster->bindSprite(Sprite::create(spPath.c_str()));

		// ���������󵽹����б�
		m_monsterList.pushBack(monster);

		// ����������δ���������б�
		m_notShowMonsterList.pushBack(monster);

		this->addChild(monster);
	}
	// ��ʼ����Ƿ����¹������
	this->schedule(schedule_selector(MonsterManager::showMonster));

<<<<<<< HEAD
	// ����Ƿ��й�������
	this->schedule(schedule_selector(MonsterManager::logic));

=======
>>>>>>> 242d9fd9e2218bb56c21948853acb0e3a3cae294
}

void MonsterManager::showMonster(float dt){
	int iNotShowMonsterCount = m_notShowMonsterList.size();

	if (iNotShowMonsterCount > 0){
		m_fShowTimeCount += dt;
	}

	// ��ȡ����ĵ�һ�������
	auto monsterFirstPos  = getMonsterStartPos();

<<<<<<< HEAD
	// ��δ�����б����ų��ﵽ����ʱ��Ĺ���
=======
>>>>>>> 242d9fd9e2218bb56c21948853acb0e3a3cae294
	Vector<Monster*> monsterWantToDelete;
	for (auto monster : m_notShowMonsterList){
		// ʱ��ﵽ����ĳ���ʱ�䣬�ù������
		if (m_fShowTimeCount >= monster->getfShowTime()){
			// ��ӹ��ﵽɾ���б�������Ĺ���Ҫ��δ�����б���ɾ��
			monsterWantToDelete.pushBack(monster);

			monster->setPosition(monsterFirstPos->getPos());
			monster->setVisible(true);

			// �ù��ﰴ��ָ����������
			monster->moveByPosList(m_monsterPosList);
		}
	}

	// ɾ���Ѿ������Ĺ���
	for (auto monster : monsterWantToDelete){
		m_notShowMonsterList.eraseObject(monster);
	}
<<<<<<< HEAD

	// �������������ı���Ϣ
	int iMonsterNumChange = -monsterWantToDelete.size();
	NOTIFY->postNotification("MonsterNumChange", (Ref*)iMonsterNumChange);
}

void MonsterManager::logic(float dt){
	Vector<Monster*> monsterWantToDelete;
	for (auto monster : m_monsterList){
		// ���б���ɾ���Ѿ�����Ŀ�ĵصĹ���ȼ�¼����ɾ��
		if (monster->isMoveEnd() == true){
			monsterWantToDelete.pushBack(monster);
		}
		// ���б���ɾ���Ѿ������Ĺ���ȼ�¼����ɾ��
		else if (monster->isDead() == true){
			monsterWantToDelete.pushBack(monster);
		}
	}

	// ��ʽɾ���Ĺ���
	for (auto monster : monsterWantToDelete){
		monster->removeFromParent();
		m_monsterList.eraseObject(monster);
	}

	if (m_monsterList.size() == 0){
		// ��������Ϊ0�� ��������ȫ����Ϣ
		NOTIFY->postNotification("AllMonsterDead");
	}
=======
>>>>>>> 242d9fd9e2218bb56c21948853acb0e3a3cae294
}