/*
	�������ؿ�������Ϣ��
*/
#ifndef _TollgateDataLayer_H_
#define _TollgateDataLayer_H_
#include "cocos2d.h"
USING_NS_CC;

#include "editor-support/cocostudio/CCSGUIReader.h"
#include "ui/CocosGUI.h"

using namespace cocos2d::ui;
using namespace cocostudio;

class TollgateDataLayer : public Layer{
public:
	TollgateDataLayer();
	~TollgateDataLayer();

	CREATE_FUNC(TollgateDataLayer);
	virtual bool init();

	int getiTowerSoulNum(); // ��ȡ��ǰ��������
	int getiMagicNum(); // ��ȡ��ǰħ������
private:
	void recvRefreshTowerSoulNum(Ref* pData);
	void recvRefreshMonsterNum(Ref* pData);
	void recvRefreshMagicNum(Ref* pData);
	void recvAllMonsterDead(Ref* pData);

	int m_iTowerSoulNum; // ��������
	int m_iMonsterNum; // ��������
	int m_iMagicNum; // ħ������

	Text* m_towerSoulLab; // �����ǩ
	Text* m_monsterLab; // �����ǩ
	Text* m_magicLab; // ħ����ǩ
};

#endif
