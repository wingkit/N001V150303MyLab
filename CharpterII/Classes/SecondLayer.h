#ifndef __SecondLayer_H__
#define __SecondLayer_H__
#include "cocos2d.h"
USING_NS_CC;
class SecondLayer : public Layer{
public:
	SecondLayer();
	~SecondLayer();
	CREATE_FUNC(SecondLayer);
	virtual bool init();
};
#endif