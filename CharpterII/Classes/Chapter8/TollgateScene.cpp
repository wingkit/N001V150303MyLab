#include "TollgateScene.h"
#include "Player.h"
#include "SimpleMoveController.h"

#include "ThreeDirectionController.h"

Scene* TollgateScene::createScene(){
	auto scene = Scene::create();
	auto layer = TollgateScene::create();
	scene->addChild(layer);
	
	return scene;
}

bool TollgateScene::init(){
	if (!Layer::init()){ return false;}
	Director::getInstance()->setProjection(Director::Projection::_2D);
	// ����Tiled��ͼ�� ��ӵ�������
	TMXTiledMap* map = TMXTiledMap::create("../Resources/level01.tmx");

	this->addChild(map);
	addPlayer(map);
	return true;
}

void TollgateScene::addPlayer(TMXTiledMap* map){
	Size visibleSize = Director::getInstance()->getVisibleSize();

	// ��������
	Sprite* playerSprite = Sprite::create("../Resources/player.png");

	// ������󶨵���ҵĶ�����
	Player* mPlayer = Player::create();
	mPlayer->bindSprite(playerSprite);
	mPlayer->run();
	mPlayer->setTiledMap(map);
	// ���ض����
	TMXObjectGroup* objGroup = map->getObjectGroup("objects");

	// ��������������
	ValueMap playerPointMap = objGroup->getObject("PlayerPoint");
	float playerX = playerPointMap.at("x").asFloat();
	float playerY = playerPointMap.at("y").asFloat();

	mPlayer->setPosition(Point(playerX, playerY));
	map->addChild(mPlayer);

	// ������Ҽ��ƶ�������
	SimpleMoveController* simpleMoveControll = SimpleMoveController::create();
	ThreeDirectionController* threeMoveControll = ThreeDirectionController::create();
	threeMoveControll->setiXSpeed(1);
	threeMoveControll->setiYSpeed(0);

	// �����ƶ��ٶ�
	simpleMoveControll->setiSpeed(1);

	// ������Ҫ��ӵ�����������update������
	this->addChild(threeMoveControll);
	
	// ���ÿ���������������
	mPlayer->setcontroller(threeMoveControll);
}
