/*
	描述：创建帧动画
*/

#ifndef __AnimationUtil_H__
#define __AnimationUtil_H__
#include "cocos2d.h"
USING_NS_CC;
class AnimationUtil{
public:
	/* 根据文件名字前缀创建动画对象
		name:图片名称
		delay：播放延迟
		iLoops：播放次数
	*/
	static Animation* creaateWithSingleFrameName(const char* name, float delay, int iLoops);

	/* 根据文件名字前缀创建动画对象，指定动画图片数量
		name:图片名称
		iNum:图片数量
		delay：播放延迟
		iLoops：播放次数
	*/
	static Animation* createWithFrameNameAndNum(const char* name, int iNum, float delay, int iLoops);
};
#endif