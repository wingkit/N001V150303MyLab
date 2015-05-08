/*
	������ �ӵ�����
*/

#ifndef _BulletBase_H_
#define _BulletBase_H_
#include "Entity.h"

// �ӵ��ٶ�
#define SPEED_DEFAULT 10
#define SPEED_NORMAL 5

class BulletBase : public Entity{
public:
	BulletBase();
	~BulletBase();

	// ��������Ŀ��
	void lockAim(Entity* entity);

	// ��ȡ����Ŀ��
	Entity* getAim();

	// �Ƿ�����ʹ��
	void setUsed(bool isUsed);
	bool isUsed();

	// �Ƿ�ﵽĿ��
	bool isArrive();

protected:
	// ��������Ŀ��ʱ���ã���������������
	virtual void onLockAim(Entity* aim) = 0;

	bool m_isArrive; // �Ƿ�ﵽ�˹���Ŀ�꣨�Ƿ񹥻���Ŀ�꣩

private:
	bool m_isUsed; // ����Ƿ��Ѿ���ʹ����
	Entity* m_aim; // ����Ŀ��

	CC_SYNTHESIZE(int, m_iAtkValue, iAtkValue); // ������
	CC_SYNTHESIZE(int, m_iSpeed, iSpeed); // �ٶ�
};
#endif