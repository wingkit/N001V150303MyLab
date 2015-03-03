#include "NotificationScene.h"
#include "OtherLayer.h"
#include "NotifyUtil.h"

Scene* NotificationScene::createScene(){
	Scene* scene = Scene::create();
	Layer* layer = NotificationScene::create();
	scene->addChild(layer);

	auto otherLayer = OtherLayer::create();
	scene->addChild(otherLayer);
	return scene;
}

bool NotificationScene::init(){
	if (!Layer::init()) return false;

	// 订阅消息类型为test的消息， 不传递数据
	NotificationCenter::getInstance()->addObserver(
		this,
		callfuncO_selector(NotificationScene::testMsg),
		"test",
		NULL);
	// 3秒后发布test消息
	this->schedule(schedule_selector(NotificationScene::sendMsg), 3.0f);


	NotifyUtil::getInstance()->addObserver("LikeHer", [](Ref* data){
		log("Recv Msg:%s", data);
	});

	NotifyUtil::getInstance()->addObserver("LikeHer", [](Ref* data){
		log("Gongxi Gongxi~");
	});

	NotifyUtil::getInstance()->addObserver("LikeHer", [](Ref* data){
		log("ai yo, bu cuo o~");
	});

	NotifyUtil::getInstance()->postNotification("LikeHer", (Ref*)"hehe");

	Size visibleSize = Director::getInstance()->getVisibleSize();
	Point origin = Director::getInstance()->getVisibleOrigin();

	/////////////////////////////
	// 2. add a menu item with "X" image, which is clicked to quit the program
	//    you may modify it.

	// add a "close" icon to exit the progress. it's an autorelease object
	auto closeItem = MenuItemImage::create(
		"../Resources/CloseNormal.png",
		"../Resources/CloseSelected.png",
		CC_CALLBACK_1(NotificationScene::menuCloseCallback, this));

	closeItem->setPosition(Point(origin.x + visibleSize.width - closeItem->getContentSize().width/2 ,
		origin.y + closeItem->getContentSize().height/2));

	// create menu, it's an autorelease object
	auto menu = Menu::create(closeItem, NULL);
	menu->setPosition(Point::ZERO);
	this->addChild(menu, 1);
	testSprite = Sprite::create("../Resources/player.png");
	testSprite->retain();
	return true;
}

void NotificationScene::sendMsg(float dt){
	// 发布test消息， 不传递数据
	//NotificationCenter::getInstance()->postNotification("test", (Ref*)"NotificationScene Msg!");
	NotificationCenter::getInstance()->postNotification("test", NULL);
}

void NotificationScene::testMsg(Ref* pSender){
	log("testMsg");
}


void NotificationScene::menuCloseCallback(Ref* pSender)
{
#if (CC_TARGET_PLATFORM == CC_PLATFORM_WP8) || (CC_TARGET_PLATFORM == CC_PLATFORM_WINRT)
	MessageBox("You pressed the close button. Windows Store Apps do not implement a close button.","Alert");
	return;
#endif
	testSprite->getPosition();
	//Director::getInstance()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
	//exit(0);
#endif
}