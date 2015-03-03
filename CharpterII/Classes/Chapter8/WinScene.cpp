#include "WinScene.h"

Scene* WinScene::createScene(){
	auto scene = Scene::create();
	auto layer = WinScene::create();
	scene->addChild(layer);
	return scene;
}

bool WinScene::init(){
	if (!Layer::init()) return false;
	Size visibleSize = Director::getInstance()->getVisibleSize();
	auto label = LabelTTF::create("You Win", "Arial", 24);
	label->setPosition(Point(visibleSize.width/2, visibleSize.height/2));
	this->addChild(label);

	return true;
}