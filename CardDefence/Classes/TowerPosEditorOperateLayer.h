#ifndef _TowerPosEditorOperateLayer_H_
#define _TowerPosEditorOperateLayer_H_
#include "cocos2d.h"
#include "editor-support/cocostudio/CCSGUIReader.h"
#include "ui/CocosGUI.h"
#include "cocos-ext.h"

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
	// �༭��
	TowerPosEditorLayer* m_editorLayer;

	// �����ť
	void outputBtnOnClick(Ref*, TouchEventType type);
	// �ı�ģʽ��ť
	void changeModeBtnOnClick(Ref*, TouchEventType type);
	// ��һ�ذ�ť
	void nextLevelBtnOnClick(Ref*, TouchEventType type);
	// ��һ�ذ�ť
	void preLevelBtnOnClick(Ref*, TouchEventType type);

	// ���ƺ���
	void onDraw(const kmMat4 &transform, bool transformUpdated);
	CustomCommand _customCommand;
};
#endif