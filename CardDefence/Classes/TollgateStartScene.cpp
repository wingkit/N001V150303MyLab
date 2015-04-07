#include "TollgateStartScene.h"
#include "SceneManager.h"
#include "GlobalClient.h"
Scene* TollgateStartScene::createScene(){
	auto scene = Scene::create();
	TollgateStartScene* layer = TollgateStartScene::create();
	scene->addChild(layer);
	return scene;
}

bool TollgateStartScene::init(){
	bool bRet = false;

	do {
		CC_BREAK_IF(!Layer::init());
		// ¼ÓÔØUI
		auto UI = cocostudio::GUIReader::getInstance()->widgetFromJsonFile("WelScene/WelScene_1.ExportJson");
		this->addChild(UI);

		// Ìí¼Ó±³¾°ÒôÀÖ
		CocosDenshion::SimpleAudioEngine::getInstance()->playBackgroundMusic(StringUtils::format("music/tollgate_bg.mp3").c_str(), true);

		Button* playBtn = (Button*)Helper::seekWidgetByName(UI, "playBtn");
		Button* selectBtn = (Button*)Helper::seekWidgetByName(UI, "selectBtn");
		Button* editBtn = (Button*)Helper::seekWidgetByName(UI, "editBtn");

		playBtn->addTouchEventListener(this, toucheventselector(TollgateStartScene::playBtn));
		selectBtn->addTouchEventListener(this, toucheventselector(TollgateStartScene::selectBtn));
		editBtn->addTouchEventListener(this, toucheventselector(TollgateStartScene::editBtn));

		bRet = true;

	} while(0);
	return bRet;
}

void TollgateStartScene::playBtn(Ref* target, TouchEventType type){
	if (type != TouchEventType::TOUCH_EVENT_ENDED){
		return ;
	}
	GlobalClient::getInstance()->setiCurTollgateLevel(0);
	SceneManager::getInstance()->changeScene(SceneManager::en_TollgateScene);
}

void TollgateStartScene::selectBtn(Ref* target, TouchEventType type){
	if (type != TouchEventType::TOUCH_EVENT_ENDED){
		return ;
	}
	SceneManager::getInstance()->changeScene(SceneManager::en_TollgateSelectScene);
}

void TollgateStartScene::editBtn(Ref* target, TouchEventType type){
	if (type != TouchEventType::TOUCH_EVENT_ENDED){
		return ;
	}
		SceneManager::getInstance()->changeScene(SceneManager::en_TollgateEditorScene);
}
