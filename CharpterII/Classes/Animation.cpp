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
	// ����һ������
	Sprite* runSp = Sprite::create("../Resources/sprite0.png");
	runSp->setPosition(Point(400, 200));
	this->addChild(runSp);

	// ����ͼƬ֡�������
	SpriteFrameCache* frameCache = SpriteFrameCache::getInstance();
	frameCache->addSpriteFramesWithFile("../Resources/grossini.plist", "../Resources/grossini.png");

	// �ø������ߴ�������
	Animation* animation = AnimationUtil::creaateWithSingleFrameName("grossini_dance_", 0.1f, -1);
	//Animation* animation = AnimationUtil::createWithFrameNameAndNum("run", 14, 0.1f, -1);

	runSp->runAction(Animate::create(animation));
	// ����Ҳ�Ƕ�����ֱ��ִ�ж�������
	//runSp->runAction(createAnimate2());
	return true;
}

Animate* RunAnimation::createAnimatel(){
	int iFrameNum = 2;
	SpriteFrame* frame = NULL;
	Vector<SpriteFrame*> frameVec;

	// ��һ���б������е�SpriteFrame����
	for (int i = 0; i <= iFrameNum; i ++){
		// ��ÿһ��ͼƬ����SpriteFrame����
		frame = SpriteFrame::create(StringUtils::format("sprite%d.png",i), Rect(0,0,130,130));
		frameVec.pushBack(frame);
	}
	// ʹ��SpriteFrame�б�����������
	Animation* animation = Animation::createWithSpriteFrames(frameVec);
	animation->setLoops(-1);
	animation->setDelayPerUnit(0.1f);
	
	// ��������װ��һ������
	Animate* action = Animate::create(animation);
	return action;
}

Animate* RunAnimation::createAnimate2(){
	
	// ����ͼƬ֡�����
	SpriteFrameCache* frameCache = SpriteFrameCache::getInstance();
	frameCache->addSpriteFramesWithFile("../Resources/grossini.plist", "../Resources/grossini.png");
	
	int iFrameNum = 14;
	SpriteFrame* frame = NULL;
	Vector<SpriteFrame*> frameVec;

	// ��һ���б������е�SpriteFrame����
	for (int i = 01; i <= iFrameNum; i ++){
		// ��ÿһ��ͼƬ����SpriteFrame����
		frame = frameCache->getSpriteFrameByName(StringUtils::format("grossini_dance_%d.png",i));
		frameVec.pushBack(frame);
	}
	// ʹ��SpriteFrame�б�����������
	Animation* animation = Animation::createWithSpriteFrames(frameVec);
	animation->setLoops(-1);
	animation->setDelayPerUnit(0.1f);

	// ��������װ��һ������
	Animate* action = Animate::create(animation);
	return action;
}