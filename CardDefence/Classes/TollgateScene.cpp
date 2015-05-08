#include "TollgateScene.h"
#include "GlobalParam.h"
#include "TollgateMapLayer.h"
<<<<<<< HEAD
#include "TollgateDataLayer.h"

Scene* TollgateScene::createScene(){
	auto scene = Scene::create();

	TollgateScene* tgLayer = TollgateScene::create();
	TollgateMapLayer* mapLayer = TollgateMapLayer::create();
	TollgateDataLayer* dataLayer = TollgateDataLayer::create();

	scene->addChild(mapLayer, 1, TAG_MAP_LAYER);
	scene->addChild(tgLayer, 3);
	scene->addChild(dataLayer, 5, TAG_DATA_LAYER);

	mapLayer->initData();
=======

Scene* TollgateScene::createScene(){
	auto scene = Scene::create();
	TollgateScene* tgLayer = TollgateScene::create();

	TollgateMapLayer* mapLayer = TollgateMapLayer::create();

	scene->addChild(mapLayer, 1, TAG_MAP_LAYER);
	scene->addChild(tgLayer, 3);

>>>>>>> 242d9fd9e2218bb56c21948853acb0e3a3cae294
	return scene;
}

bool TollgateScene::init(){
	if (!Layer::init()){
		return false;
	}
	return true;
}
