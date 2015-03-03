#ifndef _NotificationScene_H_
#define _NotificationScene_H_
#include "cocos2d.h"
using namespace cocos2d;
class NotificationScene : public Layer{
public:
	static Scene* createScene();
	virtual bool init();
	CREATE_FUNC(NotificationScene);

	// ������Ϣ
	void sendMsg(float dt);

	// ������Ϣ�Ļص�����
	void testMsg(Ref* pSender);

	void menuCloseCallback(Ref* pSender);
private:
	Sprite* testSprite;
};
#endif