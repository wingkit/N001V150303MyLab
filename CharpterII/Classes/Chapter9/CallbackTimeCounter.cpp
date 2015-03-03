#include "CallbackTimeCounter.h"

bool CallbackTimeCounter::init(){
	m_isCounting = false;
	this->scheduleUpdate();
	return true;
}

void CallbackTimeCounter::update(float dt){
	if (m_isCounting == false) return;
	m_fTime += dt;

	// ����ʱ�䣬 �ص�����
	if (m_fTime >= m_fCBTime){
		m_func();
		m_isCounting = false;
	}
}

void CallbackTimeCounter::start(float fCBTime, std::function<void()> func){
	m_fCBTime = fCBTime;
	m_fTime = 0;
	m_func  = func;
	m_isCounting = true;
}