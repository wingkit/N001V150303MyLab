#ifndef __RunAnimation_H__
#define __RunAnimation_H__
#include "cocos2d.h"
USING_NS_CC;
class RunAnimation : public Layer{
public:
	static Scene* createScene();
	virtual bool init();
	CREATE_FUNC(RunAnimation);
	Animate* createAnimatel();
private:
	Animate* createAnimate2();
};
#endif