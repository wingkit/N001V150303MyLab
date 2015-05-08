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
	// 创建怪物
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
	// 加载怪物坐标对象
<<<<<<< HEAD
	Vector<PosBase*> posList = PosLoadUtil::getInstance()->loadPosWithJsonFile("monsterPos", StringUtils::format("monsterPos_level_%d.json", iCurLevel).c_str(), enTowerPos, this, 10, false);
	// 当没有用户自定义的json文件时，采用默认的plist文件
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

	// 读取配置文件
	std::string sMonsterConfPath = StringUtils::format("tollgate/monster_level_%d.plist", iCurLevel);
	ValueMap fileDataMap = FileUtils::getInstance()->getValueMapFromFile(sMonsterConfPath.c_str());
<<<<<<< HEAD
	// 怪物数量
=======

>>>>>>> 242d9fd9e2218bb56c21948853acb0e3a3cae294
	int size = fileDataMap.size();
	for (int i = 1; i <= size; i++){
		Value value = fileDataMap.at(StringUtils::toString(i));
		ValueMap data = value.asValueMap();
		// 从怪物出场配置文件读取怪物ID和出场时间，保存所有怪物到未出场列表
		int id = data["id"].asInt();
		float fShowTime = data["showTime"].asFloat();

		auto monster = Monster::createFromCsvFileByID(id);
<<<<<<< HEAD
		if (monster == NULL) {log("the monster is Null, read csv file fail!"); return;}
=======
>>>>>>> 242d9fd9e2218bb56c21948853acb0e3a3cae294
		monster->setfShowTime(fShowTime);
		monster->setVisible(false);

		// 设置怪物精灵
		std::string spPath = StringUtils::format("sprite/monster/monster_%d.png", monster->getiModelID());
		monster->bindSprite(Sprite::create(spPath.c_str()));

		// 保存怪物对象到怪物列表
		m_monsterList.pushBack(monster);

		// 保存怪物对象到未出场怪物列表
		m_notShowMonsterList.pushBack(monster);

		this->addChild(monster);
	}
	// 开始检查是否有新怪物出场
	this->schedule(schedule_selector(MonsterManager::showMonster));

<<<<<<< HEAD
	// 检查是否有怪物死亡
	this->schedule(schedule_selector(MonsterManager::logic));

=======
>>>>>>> 242d9fd9e2218bb56c21948853acb0e3a3cae294
}

void MonsterManager::showMonster(float dt){
	int iNotShowMonsterCount = m_notShowMonsterList.size();

	if (iNotShowMonsterCount > 0){
		m_fShowTimeCount += dt;
	}

	// 获取怪物的第一个坐标点
	auto monsterFirstPos  = getMonsterStartPos();

<<<<<<< HEAD
	// 从未出场列表中排出达到出场时间的怪物
=======
>>>>>>> 242d9fd9e2218bb56c21948853acb0e3a3cae294
	Vector<Monster*> monsterWantToDelete;
	for (auto monster : m_notShowMonsterList){
		// 时间达到怪物的出场时间，让怪物出场
		if (m_fShowTimeCount >= monster->getfShowTime()){
			// 添加怪物到删除列表，出场后的怪物要从未出场列表中删除
			monsterWantToDelete.pushBack(monster);

			monster->setPosition(monsterFirstPos->getPos());
			monster->setVisible(true);

			// 让怪物按照指定坐标行走
			monster->moveByPosList(m_monsterPosList);
		}
	}

	// 删除已经出场的怪物
	for (auto monster : monsterWantToDelete){
		m_notShowMonsterList.eraseObject(monster);
	}
<<<<<<< HEAD

	// 发布怪物数量改变消息
	int iMonsterNumChange = -monsterWantToDelete.size();
	NOTIFY->postNotification("MonsterNumChange", (Ref*)iMonsterNumChange);
}

void MonsterManager::logic(float dt){
	Vector<Monster*> monsterWantToDelete;
	for (auto monster : m_monsterList){
		// 从列表中删除已经到达目的地的怪物，先记录，后删除
		if (monster->isMoveEnd() == true){
			monsterWantToDelete.pushBack(monster);
		}
		// 从列表中删除已经死亡的怪物，先记录，后删除
		else if (monster->isDead() == true){
			monsterWantToDelete.pushBack(monster);
		}
	}

	// 正式删除的怪物
	for (auto monster : monsterWantToDelete){
		monster->removeFromParent();
		m_monsterList.eraseObject(monster);
	}

	if (m_monsterList.size() == 0){
		// 怪物数量为0， 发布怪物全灭消息
		NOTIFY->postNotification("AllMonsterDead");
	}
=======
>>>>>>> 242d9fd9e2218bb56c21948853acb0e3a3cae294
}