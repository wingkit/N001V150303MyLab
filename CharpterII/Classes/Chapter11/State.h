#ifndef _State_H_
#define _State_H_
#include "cocos2d.h"
#include "EnumMsgType.h"
USING_NS_CC;
class MutouT;
class State {
public:
	virtual void execute(MutouT* mutou, EnumMsgType enMsgType) = 0;
};
#endif