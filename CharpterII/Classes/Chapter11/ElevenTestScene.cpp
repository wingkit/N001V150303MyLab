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
	// �½�ľͷ��ɫ
	MutouT* mMutou = MutouT::create();

	// ��ʼ��ľͷ��״̬Ϊ��Ϣ
	mMutou->getFSM()->changeState(new StateRest());

	this->addChild(mMutou);


	// ģ���¼��ķ���
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

