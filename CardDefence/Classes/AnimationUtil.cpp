#include "AnimationUtil.h"

Animation* AnimationUtil::creaateWithSingleFrameName(const char* name, float delay, int iLoops){
	SpriteFrameCache* cache = SpriteFrameCache::getInstance();

	Vector<SpriteFrame*> frameVec;
	SpriteFrame* frame = NULL;
	int index = 2;// 从第二张开始

	do {
		frame = cache->getSpriteFrameByName(StringUtils::format("%s%d.png", name, index++));

		// 不断地获取SpriteFrame对象， 直到获取的值为NULL
		if (frame == NULL){
			break;
		}

		frameVec.pushBack(frame);
	} while(true);

	Animation* animation = Animation::createWithSpriteFrames(frameVec);
	animation->setLoops(iLoops);
	animation->setRestoreOriginalFrame(true);
	animation->setDelayPerUnit(delay);
	return animation;
}

Animation* AnimationUtil::createWithFrameNameAndNum(const char* name, int iNum, float delay, int iLoops){
	SpriteFrameCache* cache = SpriteFrameCache::getInstance();

	Vector<SpriteFrame*> frameVec;
	SpriteFrame* frame = NULL;

	int index = 1;
	for (int i = 1; i <= iNum; i++){
		frame = cache->getSpriteFrameByName(StringUtils::format("%s%d.png", name, i));
		if (frame == NULL){ break;}
		frameVec.pushBack(frame);

	}

	Animation* animation = Animation::createWithSpriteFrames(frameVec);
	animation->setLoops(iLoops);
	animation->setRestoreOriginalFrame(true);
	animation->setDelayPerUnit(delay);
	return animation;
}