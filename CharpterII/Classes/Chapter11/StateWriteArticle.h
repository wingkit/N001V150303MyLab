#ifndef _StateWriteArticle_H_
#define _StateWriteArticle_H_
#include "State.h"
#include "EnumMsgType.h"
class MutouT;
class StateWriteArticle : public State{
public:
	virtual void execute(MutouT* mutou, EnumMsgType enMsgType);
};
#endif