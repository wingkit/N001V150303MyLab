#include "ElevenTestScene.h"
#include "Mutou.h"
#include "MutouT.h"
#include "StateRest.h"
#include "MutouTFSM.h"
#include "EnumMsgType.h"
Scene* ElevenTestScene::createScene(){
	auto scene = Scene::create();
	auto layer = ElevenTestScene::create();
	scene->addChild(layer);
	return scene;

}

bool ElevenTestScene::init(){
	if(!Layer::init())return false;
	// 新建木头角色
	MutouT* mMutou = MutouT::create();

	// 初始化木头的状态为休息
	mMutou->getFSM()->changeState(new StateRest());

	this->addChild(mMutou);


	// 模拟事件的发生
	auto notify = NotificationCenter::getInstance();
	notify->postNotification(StringUtils::toString(en_Msg_WantToWriteCode));
	notify->postNotification(StringUtils::toString(en_Msg_WantToRest));
	notify->postNotification(StringUtils::toString(en_Msg_WantToWriteArticle));
	notify->postNotification(StringUtils::toString(en_Msg_WantToRest));
	notify->postNotification(StringUtils::toString(en_Msg_WantToWriteCode));
	notify->postNotification(StringUtils::toString(en_Msg_WantToRest));
	notify->postNotification(StringUtils::toString(en_Msg_WantToWriteArticle));
	notify->postNotification(StringUtils::toString(en_Msg_WantToRest));
	return true;
}

