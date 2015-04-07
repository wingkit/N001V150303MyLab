/*
	������ �ؿ���ͼͼ��

*/

#ifndef _TollgateMapLayer_H_
#define _TollgateMapLayer_H_
#include "cocos2d.h"
USING_NS_CC;

class HeroManager;
class MonsterManager;
class TollgateMapLayer : public Layer{
public:
	TollgateMapLayer();
	~TollgateMapLayer();

	CREATE_FUNC(TollgateMapLayer);
	virtual bool init();
private:
	// ��ǰ�ؿ�
	int m_iCurLevel;
	HeroManager* m_heroMgr;
	MonsterManager* m_monsterMgr;

	// ��ȡ�ؿ�����
	void loadConfig();

	void logic(float dt);

	void createEndPoint();
	void createStartPoint();
};
#endif