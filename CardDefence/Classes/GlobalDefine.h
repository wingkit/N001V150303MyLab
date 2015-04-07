#ifndef _GlobalDefine_H_
#define _GlobalDefine_H_
#include "cocos2d.h"
// #���ַ����� ##��һ�����ӷ�
// ����bool������ ����get��set����
#define CC_CC_SYNTHESIZE_BOOL(varName, funcName)\
	protected: bool varName; \
	public: bool is##funName(void) const {return varName;}\
	public: void set##funcName(bool var){ varName = var;}

// ��Ϣ�ɷ�
#define NOTIFY cocos2d::NotificationCenter::getInstance()
#endif