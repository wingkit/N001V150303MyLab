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
	float m_fTotalDTTIme; // update ����ִ�м���ۼӵ�ʱ��
	float m_fCountTime; // ����update�������м�ʱ���ۼƵ�ʱ��
	TimeCounter* m_timeCounter;
};
#endif