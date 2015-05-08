#ifndef _PosBase_H_
#define _PosBase_H_
#include "cocos2d.h"
USING_NS_CC;
// ��̨������
class PosBase : public Layer{
public:
	PosBase();
	~PosBase();

	static PosBase* create(Point pos);
	static PosBase* create(Point pos, bool isDebug);
	bool init(Point pos);
	bool init(Point pos, bool isDebug);

	CC_SYNTHESIZE(Point, m_pos, Pos);

	// �ж������Ƿ���뷶Χ
	virtual bool isClickMe(Point pos);  
	
	// ������رյ�ģʽ
	void setDebug(bool isDebug);

protected:
	// �Ƿ�Ϊ����״̬
	bool m_isDebug;
};
#endif