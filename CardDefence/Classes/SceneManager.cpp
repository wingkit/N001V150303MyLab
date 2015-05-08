#include "SceneManager.h"
#include "TollgateScene.h"
#include "TowerPosEditorScene.h"
<<<<<<< HEAD
#include "TollgateSelectScene.h"
#include "WinScene.h"
#include "GameOverScene.h"
#include "TollgateStartScene.h"
=======

>>>>>>> 242d9fd9e2218bb56c21948853acb0e3a3cae294
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
<<<<<<< HEAD
	case en_TollgateStartScene: // ��ʼ����
		pScene = TollgateStartScene::createScene();
		break;
=======
>>>>>>> 242d9fd9e2218bb56c21948853acb0e3a3cae294
	case en_TollgateScene: // �ؿ�����
		pScene = TollgateScene::createScene();
		break;
	case en_TollgateEditorScene: // �ؿ��༭������
		pScene = TowerPosEditorScene::createScene();
		break;
	case en_WinScene: // ʤ������
<<<<<<< HEAD
		pScene = WinScene::createScene();
		break;
	case en_GameOverScene: // ��Ϸ��������
		pScene = GameOverScene::createScene();
		break;
	case en_TollgateSelectScene: // �ؿ�ѡ�񳡾�
		pScene = TollgateSelectScene::createScene();
=======
		break;
	case en_GameOverScene: // ��Ϸ��������
>>>>>>> 242d9fd9e2218bb56c21948853acb0e3a3cae294
		break;
	}

	if (pScene == NULL){
		return;
	}

	Director* pDirector = Director::getInstance();
	Scene* curScene = pDirector->getRunningScene();
	// �ж������һ�μ������õ�ǰ�������룬����������滻Ϊ��ǰ����
	if (curScene == NULL){
		pDirector->runWithScene(pScene);
	} else {
		pDirector->replaceScene(pScene);
	}
}