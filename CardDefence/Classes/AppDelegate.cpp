#include "AppDelegate.h"
#include "HelloWorldScene.h"
#include "SceneManager.h"
#include "TowerPosEditorScene.h"
USING_NS_CC;

AppDelegate::AppDelegate() {

}

AppDelegate::~AppDelegate() 
{
}

bool AppDelegate::applicationDidFinishLaunching() {
    // initialize director
    auto director = Director::getInstance();
    auto glview = director->getOpenGLView();
    if(!glview) {
        glview = GLView::create("My Game");
		glview->setFrameSize(800, 480);
        director->setOpenGLView(glview);
    }
	// 游戏设计大小
	glview->setDesignResolutionSize(800, 480, ResolutionPolicy::SHOW_ALL);
    // turn on display FPS
    director->setDisplayStats(true);

    // set FPS. the default value is 1.0/60 if you don't call this
    director->setAnimationInterval(1.0 / 60);

    //// create a scene. it's an autorelease object
    //auto scene = TowerPosEditorScene::createScene();

    //// run
    //director->runWithScene(scene);
	
	// 调用场景管理器切换场景
<<<<<<< HEAD
	SceneManager::getInstance()->changeScene(SceneManager::en_TollgateStartScene);
=======
	SceneManager::getInstance()->changeScene(SceneManager::en_TollgateScene);
>>>>>>> 242d9fd9e2218bb56c21948853acb0e3a3cae294
    return true;
}

// This function will be called when the app is inactive. When comes a phone call,it's be invoked too
void AppDelegate::applicationDidEnterBackground() {
    Director::getInstance()->stopAnimation();

    // if you use SimpleAudioEngine, it must be pause
    // SimpleAudioEngine::getInstance()->pauseBackgroundMusic();
}

// this function will be called when the app is active again
void AppDelegate::applicationWillEnterForeground() {
    Director::getInstance()->startAnimation();

    // if you use SimpleAudioEngine, it must resume here
    // SimpleAudioEngine::getInstance()->resumeBackgroundMusic();
}
