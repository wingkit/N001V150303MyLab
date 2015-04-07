/************************************************************************/
/* 
	描述：坐标提取类
*/
/************************************************************************/
#include "PosLoadUtil.h"
#include "EnumPosType.h"
#include "TowerPos.h"
#include "MonsterPos.h"
#include "json/document.h"
#include "json/reader.h"
#include "json/stringbuffer.h"

PosLoadUtil* PosLoadUtil::m_posLoadUtil = NULL;

PosLoadUtil* PosLoadUtil::getInstance(){
	if (m_posLoadUtil == NULL){
		m_posLoadUtil = new PosLoadUtil();

		if (m_posLoadUtil && m_posLoadUtil->init()){
			m_posLoadUtil->autorelease();
			m_posLoadUtil->retain();
		} else {
			CC_SAFE_DELETE(m_posLoadUtil);
		}

	}

	return m_posLoadUtil;
}

bool PosLoadUtil::init(){
	return true;
}

Vector<PosBase*> PosLoadUtil::loadPosWithFile(const char* sFilePath, EnumPosType enPosType, Node* container, int iLevel, bool isDebug){
	Vector<PosBase*> posList;
	ValueMap fileDataMap = FileUtils::getInstance()->getValueMapFromFile(sFilePath);
	int size = fileDataMap.size();
	for (int i = 1; i <= size; i++){
		Value value = fileDataMap.at(StringUtils::toString(i));
		ValueMap data = value.asValueMap();

		// 创建坐标对象
		PosBase* posBase = NULL;
		switch(enPosType){
		case enTowerPos:
			posBase = TowerPos::create(Point(data["x"].asInt(), data["y"].asInt()), isDebug);
			break;
		case enMonsterPos:
			posBase = MonsterPos::create(Point(data["x"].asInt(), data["y"].asInt()), isDebug);
			break;
		default:
			posBase = TowerPos::create(Point(data["x"].asInt(), data["y"].asInt()), isDebug);
		}
		posList.pushBack(posBase);
		if (container  != NULL){
			container->addChild(posBase, iLevel);
		}
	}
	return posList;
}

Vector<PosBase*> PosLoadUtil::loadPosWithJsonFile(const char* key, const char* sFilePath, EnumPosType enPosType, Node* container, int iLevel, bool isDebug){
	Vector<PosBase*> posList;
	rapidjson::Document readdoc;
	ssize_t size = 0;
	std::string jStr;
	auto path = FileUtils::getInstance()->getWritablePath();
	path.append(sFilePath);
	
	// 如果文件不存在返回
	if (!FileUtils::getInstance()->isFileExist(path.c_str())) {
		log("isFileExist Error: the file is not exist!");
		return posList;
	}
	unsigned char* jData = FileUtils::getInstance()->getFileData(path.c_str(), "r", &size);
	jStr = std::string((const char*)jData, size);

	// kParseDefaultFlags = 0,			//!< Default parse flags. Non-destructive parsing. Text strings are decoded into allocated buffer.
	//kParseInsituFlag = 1			//!< In-situ(destructive) parsing.
	readdoc.Parse<0>(jStr.c_str());
	if (readdoc.HasParseError()){
		log("GetParseError %s\n", readdoc.GetParseError());
	}
	if (!readdoc.IsObject()) return posList;
	rapidjson::Value& __json = readdoc[key];
	for ( rapidjson::Document::MemberIterator item = __json.MemberonBegin(); item != __json.MemberonEnd(); item++){
		const char* name = item->name.GetString();  
		const float x = item->value["x"].GetDouble();
		const float y = item->value["y"].GetDouble();
		log("name:%s,value:%d,%d", name, x, y);
		// 创建坐标对象
		PosBase* posBase = NULL;
		switch(enPosType){
		case enTowerPos:
			posBase = TowerPos::create(Point(x, y), isDebug);
			break;
		case enMonsterPos:
			posBase = MonsterPos::create(Point(x, y), isDebug);
			break;
		default:
			posBase = TowerPos::create(Point(x, y), isDebug);
		}
		posList.pushBack(posBase);
		if (container  != NULL){
			container->addChild(posBase, iLevel);
		}
	}
	return posList;
}