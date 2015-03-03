#include "MutouTFSM.h"
#include "EnumMsgType.h"
#define NOTIFY NotificationCenter::getInstance()

MutouTFSM::~MutouTFSM(){
	NOTIFY->removeAllObservers(this);
}


MutouTFSM* MutouTFSM::createWithMutouT(MutouT* mutou){
	MutouTFSM* fsm = new MutouTFSM();
	if (fsm && fsm->initWithMutouT(mutou)){
		fsm->autorelease();
	}
	else {
		CC_SAFE_DELETE(fsm);
		fsm = NULL;
	}
	return fsm;
}

bool MutouTFSM::initWithMutouT(MutouT* mutou){
	this->mCurState = NULL;
	this->mMutou = mutou;

	// 订阅消息
	NOTIFY->addObserver(this, callfuncO_selector(MutouTFSM::onRecvWantToRest), StringUtils::toString(en_Msg_WantToRest), NULL);
	NOTIFY->addObserver(this, callfuncO_selector(MutouTFSM::onRecvWantToWriteCode), StringUtils::toString(en_Msg_WantToWriteCode), NULL);
	NOTIFY->addObserver(this, callfuncO_selector(MutouTFSM::onRecvWantToWriteAritcle), StringUtils::toString(en_Msg_WantToWriteArticle), NULL);
	return true;
}

void MutouTFSM::changeState(State* state){
	CC_SAFE_DELETE(mCurState);
	this->mCurState = state;
}

//void MutouTFSM::update(float dt){
//	this->mCurState->execute(mMutou);
//}

void MutouTFSM::onRecvWantToRest(Ref* obj){
	// 将当前事件传递给具体的状态类
	this->mCurState->execute(mMutou, en_Msg_WantToRest);
}

void MutouTFSM::onRecvWantToWriteCode(Ref* obj){
	// 将当前事件传递给具体的状态类
	this->mCurState->execute(mMutou, en_Msg_WantToWriteCode);
}

void MutouTFSM::onRecvWantToWriteAritcle(Ref* obj){
	// 将当前事件传递给具体的状态类
	this->mCurState->execute(mMutou, en_Msg_WantToWriteArticle);
}