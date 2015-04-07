#include "SceneManager.h"
#include "TollgateScene.h"
#include "TowerPosEditorScene.h"

SceneManager* SceneManager::mSceneManager = NULL;

SceneManager* SceneManager::getInstance(){
	if (mSceneManager == NULL){
		mSceneManager = new SceneManager();
		if (mSceneManager && mSceneManager->init()){
			mSceneManager->autorelease();
			mSceneManager->retain();
		} else {
			CC_SAFE_DELETE(mSceneManager);
			mSceneManager = NULL;
		}
	}
	return mSceneManager;
}

bool SceneManager::init(){
	return true;
}

void SceneManager::changeScene(EnumSceneType enSceneType){
	Scene* pScene = NULL;
	switch(enSceneType){
	case en_TollgateScene: // 关卡场景
		pScene = TollgateScene::createScene();
		break;
	case en_TollgateEditorScene: // 关卡编辑器场景
		pScene = TowerPosEditorScene::createScene();
		break;
	case en_WinScene: // 胜利场景
		break;
	case en_GameOverScene: // 游戏结束场景
		break;
	}

	if (pScene == NULL){
		return;
	}

	Director* pDirector = Director::getInstance();
	Scene* curScene = pDirector->getRunningScene();
	// 判断如果第一次加载则用当前场景载入，如果不是则替换为当前场景
	if (curScene == NULL){
		pDirector->runWithScene(pScene);
	} else {
		pDirector->replaceScene(pScene);
	}
}