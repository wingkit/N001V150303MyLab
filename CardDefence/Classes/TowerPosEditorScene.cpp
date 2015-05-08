#include "TowerPosEditorScene.h"
#include "TowerPosEditorLayer.h"
#include "TowerPosEditorOperateLayer.h"
#include "I18N.h"
TowerPosEditorScene::TowerPosEditorScene(){

}

TowerPosEditorScene::~TowerPosEditorScene(){

}

Scene* TowerPosEditorScene::createScene(){
	auto scene = Scene::create();
	auto editorLayer = TowerPosEditorLayer::create();
	scene->addChild(editorLayer, 1);

	auto operLayer = TowerPosEditorOperateLayer::create(editorLayer);
	scene->addChild(operLayer, 2);

<<<<<<< HEAD
=======
	/*TowerPos* pos = TowerPos::create(Point(200, 200), true);
	scene->addChild(pos);*/

>>>>>>> 242d9fd9e2218bb56c21948853acb0e3a3cae294
	// test I18N utility class
	log("I18N Test:%s", I18N::getInstance()->getcString(en_StrKey_Public_Confirm));
	return scene;
}

bool TowerPosEditorScene::init(){
	if (!Layer::init()) return false;
	return true;
}