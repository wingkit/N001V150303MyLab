#ifndef _SceneManager_H_
#define _SceneManager_H_
#include "cocos2d.h"
using namespace cocos2d;
class SceneManager : public Ref{
public:
	// 场景枚举类
	enum EnumSceneType{
		en_TollgateScene, // 关卡场景
		en_TollgateEditorScene, // 关卡编辑器场景
		en_WinScene, // 胜利场景
		en_GameOverScene, // 游戏结束场景
<<<<<<< HEAD
		en_TollgateSelectScene, // 关卡选择场景
		en_TollgateStartScene, // 开始场景
=======
>>>>>>> 242d9fd9e2218bb56c21948853acb0e3a3cae294
	};
	// 获取场景管理器对象
	static SceneManager* getInstance();
	// 初始化
	virtual bool init();
	// 切换场景
	void changeScene(EnumSceneType enSceneType);
private:

	// 场景管理器对象
	static SceneManager* mSceneManager;
};
#endif