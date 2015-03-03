#include "Mutou.h"
bool Mutou::init(){
	this->scheduleUpdate();
	return true;

}

void Mutou::changeState(EnumState enState){
	this->enCurState = enState;

}

bool Mutou::isTire(){
	return true;
}

bool Mutou::isWantToWriteArticle(){
	float ran  = CCRANDOM_0_1();
	if (ran < 0.1f){
		return true;
	}
	return false;
}

void Mutou::writeCode(){
	log("mutou is writing Code.");
}

void Mutou::WriteArticle(){
	log("mutou is writing article.");

}

void Mutou::rest(){
	log("mutou is resting.");
}

void Mutou::update(float dt){
	// 判断在每一种状态下应该做什么事情
	switch(enCurState){
	case enStateWriteCode:
		if (isTire()){
			rest();
			changeState(enStateRest);
		}
		break;
	case enStateWriteArticle:
		if (isTire()){
			rest();
			changeState(enStateRest);
		}
		break;
	case enStateRest:
		// 有一定概率写代码，一定概率写教程，并且切换到相应状态
		if (isWantToWriteArticle()){
			WriteArticle();
			changeState(enStateWriteArticle);
		}
		else{
			writeCode();
			changeState(enStateWriteCode);
		}
		break;
	}
}