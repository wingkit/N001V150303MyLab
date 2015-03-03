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

	//// 创建计时器，要添加到场景
	//m_timeCounter = TimeCounter::create();
	//this->addChild(m_timeCounter);
	//// 开始计时
	//m_timeCounter->start();
	//this->schedule(schedule_selector(ScheduleScene::logic), 1.0f);
	//this->schedule(schedule_selector(ScheduleScene::doSomething));

	// 初始化计时器
	m_fTotalDTTIme = 0;
	m_fCountTime = 0;

	//// 间隔一秒钟执行
	//this->schedule(schedule_selector(ScheduleScene::countTime), 1.0f);
	//this->scheduleUpdate();
	//// 间隔2秒调用一次
	//this->schedule(schedule_selector(ScheduleScene::mutUpdate), 2.0f);
	//this->scheduleOnce(schedule_selector(ScheduleScene::cookFinish), 5.0f);


	// 创建定时器
	CallbackTimeCounter* cbTimeCounter = CallbackTimeCounter::create();
	this->addChild(cbTimeCounter);

	// 开始计时， 5秒钟后回调
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
	m_fTotalDTTIme += dt; // 累计执行间隔时间
	m_fCountTime += 1.0f; // 每次累加1秒，模拟秒表
	log("TotalDTTime=%f, CountTime=%f", m_fTotalDTTIme, m_fCountTime);
}