#ifndef _TollgateScene_H__
#define _TollgateScene_H__
#include "cocos2d.h"
using namespace cocos2d;
class TollgateScene : public Layer{
public:
	static Scene* createScene();
	CREATE_FUNC(TollgateScene);
	virtual bool init();
	
private:
	void addPlayer(TMXTiledMap* map);
};
#endif