#include "MutouT.h"
#include "MutouTFSM.h"
bool MutouT::init(){
	mFSM = MutouTFSM::createWithMutouT(this);
	mFSM->retain();
	this->scheduleUpdate();
	return true;

}

//void MutouT::changeState(State* state){
//	CC_SAFE_DELETE(mCurState);
//	mCurState = state;
//
//}

bool MutouT::isTire(){
	return true;
}

bool MutouT::isWantToWriteArticle(){
	float ran  = CCRANDOM_0_1();
	if (ran < 0.1f){
		return true;
	}
	return false;
}

void MutouT::writeCode(){
	log("MutouT is writing Code.");
}

void MutouT::writeArticle(){
	log("MutouT is writing article.");

}

void MutouT::rest(){
	log("MutouT is resting.");
}

void MutouT::update(float dt){
	this->mFSM->update(dt);
}

MutouTFSM* MutouT::getFSM(){
	return this->mFSM;
}