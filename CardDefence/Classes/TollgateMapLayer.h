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
<<<<<<< HEAD
	void initData();
private:
	// ��ǰ�ؿ�
	int m_iCurLevel;
	// Ӣ�۹�����
	HeroManager* m_heroMgr;
	// ���������
=======
private:
	// ��ǰ�ؿ�
	int m_iCurLevel;
	HeroManager* m_heroMgr;
>>>>>>> 242d9fd9e2218bb56c21948853acb0e3a3cae294
	MonsterManager* m_monsterMgr;

	// ��ȡ�ؿ�����
	void loadConfig();

	void logic(float dt);
<<<<<<< HEAD
	// ����������
	void createEndPoint();
	// ������ʼ��
=======

	void createEndPoint();
>>>>>>> 242d9fd9e2218bb56c21948853acb0e3a3cae294
	void createStartPoint();
};
#endif