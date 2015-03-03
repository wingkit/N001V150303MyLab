#include "SaveDataScene.h"
#include "StringUtil.h"
#include "CsvUtil.h"
#include "json/reader.h"
#include "json/writer.h"
Scene* SaveDataScene::createScene(){
	auto scene = Scene::create();
	auto layer = SaveDataScene::create();
	scene->addChild(layer);
	return scene;
}

bool SaveDataScene::init(){
	if (!Layer::init()) return false;
	// �����ɫ����
	//UserDefault::getInstance()->setStringForKey("ActorName", "mutou");

	//// ��ȡ��ɫ����
	//std::string actorName = UserDefault::getInstance()->getStringForKey("ActorName", "none");
	//log("ActorName= %s", actorName.c_str());
	//log("path= %s", UserDefault::getInstance()->getXMLFilePath());

	// ����ַ���
	auto strsList = StringUtil::getInstance()->split("mutou,xiaoruo,Cocos2d-x,Csv",",");

	// ���Խ��
	for (auto value : strsList){
		log("value=%s", value.asString().c_str());
	}

	const char* sPath = "../Resources/Monster.csv"; // ���Զ�ȡCsv�ļ�
	CsvUtil::getInstance()->loadFile(sPath); // �����ļ�
	// ��ȡ��һ�����������
	Value firstMonsterName = CsvUtil::getInstance()->getValue(2, 1, sPath);

	// ��ȡ�ڶ��������HPֵ
	Value secMonsterHp = CsvUtil::getInstance()->getValue(3, 3, sPath);

	log("firstMonsterName = %s", firstMonsterName.asString().c_str());
	log("secMonsterHp = %s", secMonsterHp.asString().c_str());

	readJson();
	writeJson();
	return true;
}

void SaveDataScene::readJson(){
	Json::Reader reader;
	Json::Value root;

	std::string data = FileUtils::getInstance()->getStringFromFile("../Resources/test1.json");

	if (reader.parse(data, root, false) == true){
		int iNum = root.size();
		for (int i = 0; i < iNum; i++){
			log("id=%d", root[i]["id"].asInt());
			log("name=%s", root[i]["name"].asCString());
			log("IQ=%f", root[i]["IQ"].asDouble());

			log("msg value money=%d", root[i]["msg"]["money"].asInt());
			log("msg value say=%s", root[i]["msg"]["say"].asCString());
		}
		
	}
}

void SaveDataScene::writeJson(){
	Json::Value root;
	Json::FastWriter writer;
	root["name"] = "Who";
	root["IQ"] = "999";

	std::string json_file = writer.write(root);

	FILE* file = fopen("testWrite.json","w");
	fprintf(file, json_file.c_str());
	fclose(file);
}


