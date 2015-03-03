#ifndef _StateWriteCode_H_
#define _StateWriteCode_H_
#include "cocos2d.h"
#include "State.h"
#include "EnumMsgType.h"
USING_NS_CC;
class MutouT;
class StateWriteCode : public State{
public:
	virtual void execute(MutouT* mutou, EnumMsgType enMsgType);
};
#endif