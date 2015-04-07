#ifndef _GlobalDefine_H_
#define _GlobalDefine_H_
#include "cocos2d.h"
// #是字符串化 ##是一个连接符
// 创建bool变量， 包括get和set方法
#define CC_CC_SYNTHESIZE_BOOL(varName, funcName)\
	protected: bool varName; \
	public: bool is##funName(void) const {return varName;}\
	public: void set##funcName(bool var){ varName = var;}

// 消息派发
#define NOTIFY cocos2d::NotificationCenter::getInstance()
#endif