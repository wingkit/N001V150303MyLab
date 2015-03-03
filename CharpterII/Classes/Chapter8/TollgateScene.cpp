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
	// 加载Tiled地图， 添加到场景中
	TMXTiledMap* map = TMXTiledMap::create("../Resources/level01.tmx");

	this->addChild(map);
	addPlayer(map);
	return true;
}

void TollgateScene::addPlayer(TMXTiledMap* map){
	Size visibleSize = Director::getInstance()->getVisibleSize();

	// 创建精灵
	Sprite* playerSprite = Sprite::create("../Resources/player.png");

	// 将精灵绑定到玩家的对象上
	Player* mPlayer = Player::create();
	mPlayer->bindSprite(playerSprite);
	mPlayer->run();
	mPlayer->setTiledMap(map);
	// 加载对象层
	TMXObjectGroup* objGroup = map->getObjectGroup("objects");

	// 加载玩家坐标对象
	ValueMap playerPointMap = objGroup->getObject("PlayerPoint");
	float playerX = playerPointMap.at("x").asFloat();
	float playerY = playerPointMap.at("y").asFloat();

	mPlayer->setPosition(Point(playerX, playerY));
	map->addChild(mPlayer);

	// 创建玩家简单移动控制器
	SimpleMoveController* simpleMoveControll = SimpleMoveController::create();
	ThreeDirectionController* threeMoveControll = ThreeDirectionController::create();
	threeMoveControll->setiXSpeed(1);
	threeMoveControll->setiYSpeed(0);

	// 设置移动速度
	simpleMoveControll->setiSpeed(1);

	// 控制器要添加到场景才能让update被调用
	this->addChild(threeMoveControll);
	
	// 设置控制器到主角身上
	mPlayer->setcontroller(threeMoveControll);
}
