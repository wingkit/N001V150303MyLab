#ifndef _CallbackTimeCounter_H_
#define _CallbackTimeCounter_H_
#include "cocos2d.h"
USING_NS_CC;
class CallbackTimeCounter : public Node{
public:
	CREATE_FUNC(CallbackTimeCounter);
	virtual bool init();
	virtual void update(float dt);
	// ��ʼ��ʱ�� ָ���ص�ʱ��ͻص�����
	void start(float fCBTime, std::function<void()> func);
private:
	float m_fTime; // ���ڼ�ʱ
	float m_fCBTime; // �ص���ʱ��
	bool m_isCounting; // ����Ƿ����ڼ�ʱ

	std::function<void()> m_func; // �ص�����
};
#endif