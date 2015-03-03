#ifndef _StateRest_H_
#define _StateRest_H_
#include "State.h"
#include "EnumMsgType.h"
class MutouT;
class StateRest : public State{
public:
	virtual void execute(MutouT* mutou, EnumMsgType enMsgType);
};
#endif