#ifndef _Entity_H__
#define _Entity_H__
#include "cocos2d.h"
#include "Controller.h"
using namespace cocos2d;

class Entity : public Layer, public ControllerListener{
public:
	// �󶨾������
	void bindSprite(Sprite* Sprite);

	// ���ÿ�����
	void setcontroller(Controller* controller);
	// ʵ��SimpleMoveListener�ӿڷ���
	virtual void setTagPosition(int x, int y);
	virtual Point getTagPosition();
protected:
	Sprite* m_sprite;
	Controller* m_controller;
};
#endif