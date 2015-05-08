/*
	描述： 炮台
*/

#ifndef _TowerBorder_H_
#define _TowerBorder_H_
#include "Entity.h"
#include "editor-support/cocostudio/CCSGUIReader.h"
<<<<<<< HEAD
#include "extensions/cocos-ext.h"
=======
#include "cocos-ext.h"
>>>>>>> 242d9fd9e2218bb56c21948853acb0e3a3cae294
#include "ui/CocosGUI.h"
using namespace cocos2d::ui;
using namespace cocostudio;
USING_NS_CC_EXT;
class Hero;
class TowerBorder : public Entity{
public:
	TowerBorder();
	~TowerBorder();

	CREATE_FUNC(TowerBorder);
	virtual bool init();

<<<<<<< HEAD
	// 炮塔英雄升级
=======
	// 升级
>>>>>>> 242d9fd9e2218bb56c21948853acb0e3a3cae294
	void upgrade();

	// 判断坐标是否进入范围
	bool isClickMe(Point pos);

	// 绑定英雄对象
	void bindHero(Hero* hero);

	// 获取英雄对象
	Hero* getHero();

	// 删除英雄对象
	void deleteHero();
	
	// 显示操作按钮
	void showTowerOprBtns();

	// 删除操作按钮
	void deleteOprBtns();

private:
	// 绑定的塔
	Hero* m_hero;
<<<<<<< HEAD
	// 所有按钮
	Vector<Button*> vecOprBtns;
=======

>>>>>>> 242d9fd9e2218bb56c21948853acb0e3a3cae294
	// 操作按钮UI
	Button* m_cancelBtn;
	Button* m_deleteBtn;
	Button* m_upgradeBtn;
<<<<<<< HEAD
	// 是否已经弹出button中
=======

>>>>>>> 242d9fd9e2218bb56c21948853acb0e3a3cae294
	bool m_isOprBtnsShow;

	// 恢复操作按钮的默认位置
	void resetOprBtns();

	void cancelClick(Ref* target, TouchEventType type);
	void deleteClick(Ref* target, TouchEventType type);
	void upgradeClick(Ref* target, TouchEventType type);
};
#endif