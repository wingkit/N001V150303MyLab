/*
	ÃèÊö£º ÆÕÍ¨×Óµ¯
*/

#ifndef _BulletNormal_H_
#define _BulletNormal_H_

#include "BulletBase.h"

class BulletNormal : public BulletBase{
public:
	BulletNormal();
	~BulletNormal();

	CREATE_FUNC(BulletNormal);
	virtual bool init();

	static BulletNormal* create(Sprite* sprite);
	bool init(Sprite* sprite);
protected:
	virtual void onLockAim(Entity* aim) override;
private:
	void moveEnd();
};
#endif