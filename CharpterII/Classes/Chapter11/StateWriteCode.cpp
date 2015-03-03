#include "StateWriteArticle.h"
#include "MutouT.h"
#include "StateWriteCode.h"
#include "StateRest.h"
#include "MutouTFSM.h"

void StateWriteCode::execute(MutouT* mutou, EnumMsgType enMsgType){
	switch(enMsgType){
	case en_Msg_WantToRest:
		mutou->rest();
		mutou->getFSM()->changeState(new StateRest());
		break;
	}
}