#ifndef _SimpleMoveController_H_
#define _SimpleMoveController_H_
#include "cocos2d.h"
#include "Controller.h"
USING_NS_CC;
class SimpleMoveController : public Controller{
public:
	CREATE_FUNC(SimpleMoveController);
	virtual bool init();
	virtual void update(float dt);

	// �����ƶ��ٶ�
	void setiSpeed(int iSpeed);
private:
	int m_iSpeed;

};
#endif