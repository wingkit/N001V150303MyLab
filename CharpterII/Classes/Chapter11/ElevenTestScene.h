#ifndef _ElevenTestScene_H_
#define _ElevenTestScene_H_
#include "cocos2d.h"
USING_NS_CC;

class ElevenTestScene : public Layer{
public:
	static Scene* createScene();
	virtual bool init();
	CREATE_FUNC(ElevenTestScene);
}; 
#endif