#ifndef _Entity_H__
#define _Entity_H__
#include "cocos2d.h"
#include "Controller.h"
using namespace cocos2d;

class Entity : public Layer, public ControllerListener{
public:
	// 绑定精灵对象
	void bindSprite(Sprite* Sprite);

	// 设置控制器
	void setcontroller(Controller* controller);
	// 实现SimpleMoveListener接口方法
	virtual void setTagPosition(int x, int y);
	virtual Point getTagPosition();
protected:
	Sprite* m_sprite;
	Controller* m_controller;
};
#endif