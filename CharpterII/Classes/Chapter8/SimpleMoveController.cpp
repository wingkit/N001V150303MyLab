#include "SimpleMoveController.h"
bool SimpleMoveController::init(){
	this->m_iSpeed = 0;

	// ÿһ֡������update������ ����Ҫ��ô����
	this->scheduleUpdate();

	return true;
}

void SimpleMoveController::update(float dt){
	if (m_controllerListener == NULL) return;

	// �����ƶ������X����ֵ
	Point pos = m_controllerListener->getTagPosition();
	pos.x += m_iSpeed;
	m_controllerListener->setTagPosition(pos.x, pos.y);
}

void SimpleMoveController::setiSpeed(int iSpeed){
	this->m_iSpeed = iSpeed;
}