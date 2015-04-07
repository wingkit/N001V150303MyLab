/*
	������ �ƶ�����������
*/

#ifndef _ControllerMoveBase_H_
#define _ControllerMoveBase_H_
#include "ControllerBase.h"
#include "Entity.h"
#define SPEED 1
// ����ƶ����ʱ�䣬ʱ��Խ�̣��ƶ�Խ��
#define CHECK_MOVE_SPEED_LVL1 0.1f
#define CHECK_MOVE_SPEED_LVL2 0.04f
#define CHECK_MOVE_SPEED_LVL3 0.03f

class ControllerMoveBase : public ControllerBase{
public:
	ControllerMoveBase();
	~ControllerMoveBase();

	CC_SYNTHESIZE(int, m_iSpeed, iSpeed); // �ƶ��ٶ�
protected:
	Entity* m_entity; // ʵ�����
	bool m_isMoving; // �Ƿ������ƶ�
	bool m_isXLeft; // ���x�����Ƿ�������
	bool m_isYUp; // ���y�����Ƿ�������
	int m_iCheckMoveSpeed; // ����ƶ��ļ��ʱ�䣬 ʱ��Խ�̣��ƶ�Խ��

	// ������ǰ�����Ŀ�����꣬�������һ��Ҫ���õ�����
	Point getNextPos(Point curPos, Point destPos);
};
#endif