#ifndef _TowerPosEditorScene_H_
#define _TowerPosEditorScene_H_
#include "cocos2d.h"
#include "TowerPos.h"
USING_NS_CC;
// �༭���ĳ���
class TowerPosEditorScene : public Layer{
public:
	TowerPosEditorScene();
	~TowerPosEditorScene();

	static Scene* createScene();
	virtual bool init();
	CREATE_FUNC(TowerPosEditorScene);
};
#endif