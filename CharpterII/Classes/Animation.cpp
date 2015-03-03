#include "Animation.h"
#include "AnimationUtil.h"
Scene* RunAnimation::createScene()
{
	// 'scene' is an autorelease object
	auto scene = Scene::create();

	// 'layer' is an autorelease object
	auto layer = RunAnimation::create();

	// add layer as a child to scene
	scene->addChild(layer);

	// return the scene
	return scene;
}

// on "init" you need to initialize your instance
bool RunAnimation::init()
{
	if ( !Layer::init() ){return false;}
	// 创建一个精灵
	Sprite* runSp = Sprite::create("../Resources/sprite0.png");
	runSp->setPosition(Point(400, 200));
	this->addChild(runSp);

	// 加载图片帧到缓存池
	SpriteFrameCache* frameCache = SpriteFrameCache::getInstance();
	frameCache->addSpriteFramesWithFile("../Resources/grossini.plist", "../Resources/grossini.png");

	// 用辅助工具创建动画
	Animation* animation = AnimationUtil::creaateWithSingleFrameName("grossini_dance_", 0.1f, -1);
	//Animation* animation = AnimationUtil::createWithFrameNameAndNum("run", 14, 0.1f, -1);

	runSp->runAction(Animate::create(animation));
	// 动画也是动作，直接执行动作即可
	//runSp->runAction(createAnimate2());
	return true;
}

Animate* RunAnimation::createAnimatel(){
	int iFrameNum = 2;
	SpriteFrame* frame = NULL;
	Vector<SpriteFrame*> frameVec;

	// 用一个列表保存所有的SpriteFrame对象
	for (int i = 0; i <= iFrameNum; i ++){
		// 用每一张图片创建SpriteFrame对象
		frame = SpriteFrame::create(StringUtils::format("sprite%d.png",i), Rect(0,0,130,130));
		frameVec.pushBack(frame);
	}
	// 使用SpriteFrame列表创建动画对象
	Animation* animation = Animation::createWithSpriteFrames(frameVec);
	animation->setLoops(-1);
	animation->setDelayPerUnit(0.1f);
	
	// 将动画包装成一个动作
	Animate* action = Animate::create(animation);
	return action;
}

Animate* RunAnimation::createAnimate2(){
	
	// 创建图片帧缓存池
	SpriteFrameCache* frameCache = SpriteFrameCache::getInstance();
	frameCache->addSpriteFramesWithFile("../Resources/grossini.plist", "../Resources/grossini.png");
	
	int iFrameNum = 14;
	SpriteFrame* frame = NULL;
	Vector<SpriteFrame*> frameVec;

	// 用一个列表保存所有的SpriteFrame对象
	for (int i = 01; i <= iFrameNum; i ++){
		// 用每一张图片创建SpriteFrame对象
		frame = frameCache->getSpriteFrameByName(StringUtils::format("grossini_dance_%d.png",i));
		frameVec.pushBack(frame);
	}
	// 使用SpriteFrame列表创建动画对象
	Animation* animation = Animation::createWithSpriteFrames(frameVec);
	animation->setLoops(-1);
	animation->setDelayPerUnit(0.1f);

	// 将动画包装成一个动作
	Animate* action = Animate::create(animation);
	return action;
}