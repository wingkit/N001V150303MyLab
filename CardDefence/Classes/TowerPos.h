<<<<<<< HEAD
/*
	ÃèÊö£ºÅÚËþ×ø±êÎ»ÖÃ
*/
=======
>>>>>>> 242d9fd9e2218bb56c21948853acb0e3a3cae294
#ifndef _TowerPos_H_
#define _TowerPos_H_
#include "cocos2d.h"
#include "PosBase.h"
#define RADIUS 32 // °ë¾¶£¿
USING_NS_CC;
class TowerPos : public PosBase{
public:
	TowerPos();
	~TowerPos();
	static TowerPos* create(Point pos);
	static TowerPos* create(Point pos, bool isDebug);
	bool init(Point pos);
	bool init(Point pos, bool isDebug);

	// ÅÐ¶Ï×ø±êÊÇ·ñ½øÈë·¶Î§
	virtual bool isClickMe(Point pos) override;

	void draw(Renderer* renderer, const kmMat4 &transform, bool transformUpdated);
private:
	void onDraw(const kmMat4 & transform, bool transformUpdated);
	CustomCommand _customCommand;
};
#endif