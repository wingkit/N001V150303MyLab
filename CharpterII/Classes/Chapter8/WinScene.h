#ifndef _WinScene_H_
#define _WinScene_H_
#include "cocos2d.h"
USING_NS_CC;
class WinScene : public Layer{
public:
	static Scene* createScene();
	virtual bool init();
	CREATE_FUNC(WinScene);
};
#endif