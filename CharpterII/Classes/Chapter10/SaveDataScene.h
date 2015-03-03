#ifndef _SaveDataScene_H_
#define _SaveDataScene_H_
#include "cocos2d.h"
USING_NS_CC;
class SaveDataScene : public Layer{
public:
	static Scene* createScene();
	virtual bool init();
	CREATE_FUNC(SaveDataScene);
	void readJson();
	void writeJson();
};
#endif