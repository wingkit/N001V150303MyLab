/*
	描述： 关卡场景
*/

#ifndef _TollgateScene_H_
#define _TollgateScene_H_
#include "cocos2d.h"

USING_NS_CC;
#define TAG_MAP_LAYER 1 // 关卡地图图层TAG
#define TAG_DATA_LAYER 2 // 关卡数据图层TAG

class TollgateScene : public Layer{
public:
	static Scene* createScene();
	virtual bool init();

	CREATE_FUNC(TollgateScene);
};
#endif