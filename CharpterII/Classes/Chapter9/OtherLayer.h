#ifndef _OtherLayer_H_
#define _OtherLayer_H_
#include "cocos2d.h"
USING_NS_CC;
class OtherLayer : public Layer{
public:
	CREATE_FUNC(OtherLayer);
	virtual bool init();
private:
	// ����test��Ϣ�Ļص�����
	void testMsg(Ref* pData);
};
#endif