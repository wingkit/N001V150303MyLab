/*
	描述：开始场景（欢迎界面）
*/
#ifndef _TollgateStartScene_H_
#define _TollgateStartScene_H_
#include "cocos2d.h"
#include "extensions/cocos-ext.h"
USING_NS_CC;
USING_NS_CC_EXT;
#include "editor-support/cocostudio/CCSGUIReader.h"
#include "ui/CocosGUI.h"
using namespace cocos2d::ui;
using namespace cocostudio;

class TollgateStartScene : public Layer{
public:
	static Scene* createScene();
	virtual bool init();

	CREATE_FUNC(TollgateStartScene);

private:
	void playBtn(Ref* target, TouchEventType type);
	void selectBtn(Ref* target, TouchEventType type);
	void editBtn(Ref* target, TouchEventType type);
};
#endif