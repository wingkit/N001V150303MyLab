/*
	描述：全局数据
*/
#ifndef _GlobalClient_H_
#define _GlobalClient_H_
#include "cocos2d.h"
USING_NS_CC;
class GlobalClient : public Ref{
public:
	static GlobalClient* getInstance();
	CREATE_FUNC(GlobalClient);
	virtual bool init();
private:
	static GlobalClient* m_GlobalClient;
	// 当前关卡level
	CC_SYNTHESIZE(int, m_iCurTollgateLevel, iCurTollgateLevel);
};
#endif