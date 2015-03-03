#include "ScheduleScene.h"
#include "CallbackTimeCounter.h"

Scene* ScheduleScene::createScene(){
	auto scene = Scene::create();
	auto layer = ScheduleScene::create();
	scene->addChild(layer);
	return scene;
}

bool ScheduleScene::init(){
	if (!Layer::init()) return false;

	//// ������ʱ����Ҫ��ӵ�����
	//m_timeCounter = TimeCounter::create();
	//this->addChild(m_timeCounter);
	//// ��ʼ��ʱ
	//m_timeCounter->start();
	//this->schedule(schedule_selector(ScheduleScene::logic), 1.0f);
	//this->schedule(schedule_selector(ScheduleScene::doSomething));

	// ��ʼ����ʱ��
	m_fTotalDTTIme = 0;
	m_fCountTime = 0;

	//// ���һ����ִ��
	//this->schedule(schedule_selector(ScheduleScene::countTime), 1.0f);
	//this->scheduleUpdate();
	//// ���2�����һ��
	//this->schedule(schedule_selector(ScheduleScene::mutUpdate), 2.0f);
	//this->scheduleOnce(schedule_selector(ScheduleScene::cookFinish), 5.0f);


	// ������ʱ��
	CallbackTimeCounter* cbTimeCounter = CallbackTimeCounter::create();
	this->addChild(cbTimeCounter);

	// ��ʼ��ʱ�� 5���Ӻ�ص�
	cbTimeCounter->start(5.0f, [&](){
		auto sprite = Sprite::create("../Resources/player.png");
		sprite->setPosition(Point(200, 200));
		this->addChild(sprite);
	});
	return true;
}


void ScheduleScene::logic(float dt){
	log("%f", m_timeCounter->getfCurTime());
}

void ScheduleScene::doSomething(float dt){
	for (int i = 0; i < 9999999; i++){

	}
}

void ScheduleScene::update(float dt){
	log("update");
	this->unscheduleUpdate();
	
}

void ScheduleScene::mutUpdate(float dt){
	log("mutUpdate dt=%f", dt);
	this->unschedule(schedule_selector(ScheduleScene::mutUpdate));
}


void ScheduleScene::cookFinish(float dt){
	log("cookFinish dt=%f", dt);
}


void ScheduleScene::countTime(float dt){
	m_fTotalDTTIme += dt; // �ۼ�ִ�м��ʱ��
	m_fCountTime += 1.0f; // ÿ���ۼ�1�룬ģ�����
	log("TotalDTTime=%f, CountTime=%f", m_fTotalDTTIme, m_fCountTime);
}