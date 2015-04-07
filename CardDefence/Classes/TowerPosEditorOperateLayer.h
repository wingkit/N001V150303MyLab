#ifndef _TowerPosEditorOperateLayer_H_
#define _TowerPosEditorOperateLayer_H_
#include "cocos2d.h"
#include "editor-support/cocostudio/CCSGUIReader.h"
#include "ui/CocosGUI.h"
#include "extensions/cocos-ext.h"

USING_NS_CC;
USING_NS_CC_EXT;

using namespace cocos2d::ui;
using namespace cocostudio;

class TowerPosEditorLayer;
class TowerPosEditorOperateLayer : public Layer{
public:
	TowerPosEditorOperateLayer();
	~TowerPosEditorOperateLayer();

	static TowerPosEditorOperateLayer* create(TowerPosEditorLayer* layer);
	virtual bool init(TowerPosEditorLayer* layer);

	void draw(Renderer *renderer, const kmMat4 &transform, bool transformUpdated);
private:
	// 编辑层
	TowerPosEditorLayer* m_editorLayer;

	// 输出按钮
	void outputBtnOnClick(Ref*, TouchEventType type);
	// 改变模式按钮
	void changeModeBtnOnClick(Ref*, TouchEventType type);
	// 下一关按钮
	void nextLevelBtnOnClick(Ref*, TouchEventType type);
	// 上一关按钮
	void preLevelBtnOnClick(Ref*, TouchEventType type);
	// 返回按钮
	void backBtnOnClick(Ref*, TouchEventType type);
	// 定时器操作Label
	void scheduleOnceLab(float dt);
	// 绘制函数
	void onDraw(const kmMat4 &transform, bool transformUpdated);
	CustomCommand _customCommand;
	// 保存返回
	LabelTTF* m_labLog;
};
#endif