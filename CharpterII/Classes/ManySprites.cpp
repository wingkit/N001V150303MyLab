#include "ManySprites.h"
#include "SecondLayer.h"
USING_NS_CC;

Scene* ManySprites::createScene()
{
	// 'scene' is an autorelease object
	auto scene = Scene::create();

	// 'layer' is an autorelease object
	auto layer = ManySprites::create();

	// add layer as a child to scene
	scene->addChild(layer);


	auto secondLayer = SecondLayer::create();
	scene->addChild(secondLayer);
	// return the scene
	return scene;
}

// on "init" you need to initialize your instance
bool ManySprites::init()
{
	//////////////////////////////
	// 1. super init first
	if ( !Layer::init() ){
		return false;
	}

	Size visibleSize = Director::getInstance()->getVisibleSize();
	Point origin = Director::getInstance()->getVisibleOrigin();


	//for (int i = 0; i < 14100; i++)
	//{
	//	Sprite* xiaoruo = Sprite::create("../Resources/sprite0.png");
	//	xiaoruo->setPosition(Point(CCRANDOM_0_1()*480, 120 + CCRANDOM_0_1()*300));
	//	//xiaoruo->setPosition(Point(240,160));
	//	this->addChild(xiaoruo);
	//	xiaoruo->setGlobalZOrder(1);
	//	xiaoruo->setOrderOfArrival(1);

	//	Sprite* xiaoruo1 = Sprite::create("../Resources/sprite1.png");
	//	xiaoruo->setPosition(Point(CCRANDOM_0_1()*480, 120 + CCRANDOM_0_1()*300));
	//	//xiaoruo1->setPosition(Point(220,160));
	//	this->addChild(xiaoruo1);
	//	xiaoruo1->setGlobalZOrder(1);
	//	xiaoruo1->setOrderOfArrival(0);
	//}

	// ½«Í»ÆÆ¼ÓÔØµ½¾«ÁéÖ¡»º´æ³Ø
	SpriteFrameCache* frameCache = SpriteFrameCache::getInstance();
	frameCache->addSpriteFramesWithFile("../Resources/persons.plist", "../Resources/persons.png");

	Sprite* sprite2 = Sprite::createWithSpriteFrameName("sprite0.png");
	sprite2->setPosition(Point(200, 200));
	this->addChild(sprite2);

	Sprite* sprite1 = Sprite::createWithSpriteFrameName("sprite1.png");
	sprite1->setPosition(Point(100, 200));
	this->addChild(sprite1);

	return true;
}


void ManySprites::menuCloseCallback(Ref* pSender)
{
#if (CC_TARGET_PLATFORM == CC_PLATFORM_WP8) || (CC_TARGET_PLATFORM == CC_PLATFORM_WINRT)
	MessageBox("You pressed the close button. Windows Store Apps do not implement a close button.","Alert");
	return;
#endif

	Director::getInstance()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
	exit(0);
#endif
}
