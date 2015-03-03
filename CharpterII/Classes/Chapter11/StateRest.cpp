#include "StateRest.h"
#include "MutouT.h"
#include "StateWriteArticle.h"
#include "StateWriteCode.h"
#include "MutouTFSM.h"
void StateRest::execute(MutouT* mutou, EnumMsgType enMsgType){
	// 有一定概率写代码，一定概率写教程，并且切换到相应状态
	switch(enMsgType){
	case en_Msg_WantToWriteArticle:
		mutou->writeArticle();
		mutou->getFSM()->changeState(new StateWriteArticle());
		break;
	case en_Msg_WantToWriteCode:
		mutou->writeCode();
		mutou->getFSM()->changeState(new StateWriteCode());
		break;
	}
}