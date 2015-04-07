#ifndef _PosBase_H_
#define _PosBase_H_
#include "cocos2d.h"
USING_NS_CC;
// 炮台坐标类
class PosBase : public Layer{
public:
	PosBase();
	~PosBase();

	static PosBase* create(Point pos);
	static PosBase* create(Point pos, bool isDebug);
	bool init(Point pos);
	bool init(Point pos, bool isDebug);

	CC_SYNTHESIZE(Point, m_pos, Pos);

	// 判断坐标是否进入范围
	virtual bool isClickMe(Point pos);  
	
	// 开启或关闭调模式
	void setDebug(bool isDebug);

protected:
	// 是否为调试状态
	bool m_isDebug;
};
#endif