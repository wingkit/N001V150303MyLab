#include "TimeCounter.h"
bool TimeCounter::init(){
	return true;
}

void TimeCounter::update(float dt){
	m_fTime += dt;
}

void TimeCounter::start(){
	m_fTime = 0;
	this->scheduleUpdate();
}

float TimeCounter::getfCurTime(){
	return m_fTime;
}