#ifndef _NotificationScene_H_
#define _NotificationScene_H_
#include "cocos2d.h"
using namespace cocos2d;
class NotificationScene : public Layer{
public:
	static Scene* createScene();
	virtual bool init();
	CREATE_FUNC(NotificationScene);

	// 发布消息
	void sendMsg(float dt);

	// 接受消息的回调函数
	void testMsg(Ref* pSender);

	void menuCloseCallback(Ref* pSender);
private:
	Sprite* testSprite;
};
#endif