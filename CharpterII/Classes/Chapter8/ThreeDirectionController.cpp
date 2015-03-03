#include "ThreeDirectionController.h"

bool ThreeDirectionController::init(){
	this->m_iXSpeed = 0;
	this->m_iYSpeed = 0;

	// ע����Ļ�����¼�
	registeTouchEvent();

	// ����update�����ĵ���
	this->scheduleUpdate();
	return true;
}

void ThreeDirectionController::update(float dt){
	if (m_controllerListener == NULL) return;
	// ���ƶ�������X��Y��������������
	Point curPos = m_controllerListener->getTagPosition();
	curPos.x += m_iXSpeed;
	curPos.y += m_iYSpeed;
	m_controllerListener->setTagPosition(curPos.x+m_iXSpeed, curPos.y+m_iYSpeed);

}

void ThreeDirectionController::setiXSpeed(int iSpeed){
	this->m_iXSpeed = iSpeed;
}

void ThreeDirectionController::setiYSpeed(int iSpeed){
	this->m_iYSpeed = iSpeed;
}

void ThreeDirectionController::registeTouchEvent(){
	auto listener = EventListenerTouchOneByOne::create();
	listener->onTouchBegan = [](Touch* touch, Event* event){
		return true;
	};

	listener->onTouchMoved = [&](Touch* touch, Event* event){
		// ��ȡ�������꣬ ����Cocos2d-x
		Point touchPos = Director::getInstance()->convertToGL(touch->getLocationInView());

		// �����ƶ��������
		Point pos = m_controllerListener->getTagPosition();

		// �ж������»�������
		int iSpeed = 0;
		if(touchPos.y > pos.y){
			iSpeed = 1;
		}
		else{
			iSpeed = -1;
		}
		setiYSpeed(iSpeed);
	};
	listener->onTouchEnded = [&](Touch* touch, Event* event){
		// ֹͣy������ƶ�
		setiYSpeed(0);
	};
	_eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);
}