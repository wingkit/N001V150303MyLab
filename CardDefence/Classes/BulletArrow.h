/*
	ÃèÊö£ºÉñ¼ý×Óµ¯
*/
#ifndef _BulletArrow_H_
#define _BulletArrow_H_
#include "BulletBase.h"

class BulletArrow : public BulletBase{
public:
	BulletArrow();
	~BulletArrow();

	CREATE_FUNC(BulletArrow);
	virtual bool init();

	static BulletArrow* create(Sprite* sprite);
	bool init(Sprite* sprite);

protected:
	virtual void onLockAim(Entity* aim) override;

private:
	void moveEnd();
};
#endif