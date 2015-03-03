#ifndef _ThreeDirectionController_H_
#define _ThreeDirectionController_H_
#include "cocos2d.h"
#include "Controller.h"
USING_NS_CC;
class ThreeDirectionController : public Controller{
public:
	CREATE_FUNC(ThreeDirectionController);
	virtual bool init();
	virtual void update(float dt);

	// ����X������ƶ��ٶ�
	void setiXSpeed(int iSpeed);
	// ����Y������ƶ��ٶ�
	void setiYSpeed(int iSpeed);
private:
	int m_iXSpeed;
	int m_iYSpeed;

	// ע����Ļ�����¼�
	void registeTouchEvent();
};
#endif