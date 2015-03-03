#ifndef _ScheduleScene_H_
#define _ScheduleScene_H_
#include "cocos2d.h"
#include "TimeCounter.h"
USING_NS_CC;
class ScheduleScene : public Layer{
public:
	static Scene* createScene();
	virtual bool init();
	CREATE_FUNC(ScheduleScene);
	void cookFinish(float dt);

	void logic(float dt);
	void doSomething(float dt);
private:
	virtual void update(float dt);
	void mutUpdate(float dt);
	void countTime(float dt);
	float m_fTotalDTTIme; // update 函数执行间隔累加的时间
	float m_fCountTime; // 利用update函数进行计时，累计的时间
	TimeCounter* m_timeCounter;
};
#endif