/*
	描述： 简单移动控制器，按照指定坐标路径移动
*/
#ifndef _ControllerSimpleMove_H_
#define _ControllerSimpleMove_H_
#include "ControllerMoveBase.h"
#include "Entity.h"
#include "PosBase.h"
class PosBase;
class ControllerSimpleMove : public ControllerMoveBase{
public:
	ControllerSimpleMove();
	~ControllerSimpleMove();

	static ControllerSimpleMove* create(Entity* entity);
	bool init(Entity* entity);

	void checkMoveUpdate(float delta);

	// 按照给定的坐标点移动
	void moveByPosList(Vector<PosBase*> posList);

	// 按照给定的坐标点和移动速度
	void moveByPosList(Vector<PosBase*> posList, int iSpeed);

	// 按照给定的坐标点、速度、移动间隔时间移动
	void moveByPosList(Vector<PosBase*> posList, int iSpeed, int iSpanTime);

	// 按照给定坐标移动
	void moveByPos(PosBase* pos);
private:
	// 移动一步
	void moveOneStep();

	// 设置下一个移动目标点
	void nextMovePos();
private:
	Vector<PosBase*> m_movePosList; // 移动目标列表
	PosBase* m_curDestPos; // 当前移动目的地

	float m_MoveSpan; // 移动间隔时间
	float m_fMoveTimeCount; // 计时器
};
#endif