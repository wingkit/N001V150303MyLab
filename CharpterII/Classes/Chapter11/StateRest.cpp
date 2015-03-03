#include "StateRest.h"
#include "MutouT.h"
#include "StateWriteArticle.h"
#include "StateWriteCode.h"
#include "MutouTFSM.h"
void StateRest::execute(MutouT* mutou, EnumMsgType enMsgType){
	// ��һ������д���룬һ������д�̳̣������л�����Ӧ״̬
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