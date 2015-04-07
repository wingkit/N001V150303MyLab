#include "ControllerMoveBase.h"

ControllerMoveBase::ControllerMoveBase(){
	m_isMoving = false;
	m_isXLeft = false;
	m_isYUp = false;
	m_iSpeed = SPEED;
	m_iCheckMoveSpeed = CHECK_MOVE_SPEED_LVL2;
	m_entity = NULL;
}

ControllerMoveBase::~ControllerMoveBase(){

}

Point ControllerMoveBase::getNextPos(Point curPos, Point destPos){
	// �ж��ƶ�����
	m_isXLeft = curPos.x > destPos.x ? true : false;

	m_isYUp = curPos.y < destPos.y ? true : false;

	// �����ƶ�������ٶ�ָ�ı䵱ǰ����
	if (curPos.x < destPos.x && m_isXLeft == false){
		curPos.x += m_iSpeed;
		if (curPos.x > destPos.x){
			curPos.x = destPos.x;
		}
	} 
	else if (curPos.x > destPos.x && m_isXLeft == true){
		curPos.x -= m_iSpeed;
		if (curPos.x < destPos.x){
			curPos.x = destPos.x;
		}
	}

	if (curPos.y < destPos.y && m_isYUp == true){
		curPos.y += m_iSpeed;
		if (curPos.y > destPos.y){
			curPos.y = destPos.y;
		}
	} 
	else if (curPos.y > destPos.y && m_isYUp == false){
		curPos.y -= m_iSpeed;
		if (curPos.y < destPos.y){
			curPos.y = destPos.y;
		}
	}

	return curPos;
}