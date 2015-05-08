#ifndef _GlobalDefine_H_
#define _GlobalDefine_H_
#include "cocos2d.h"
// #���ַ����� ##��һ�����ӷ�
// ����bool������ ����get��set����
#define CC_SYNTHESIZE_BOOL(varName, funName)\
	protected: bool varName; \
	public: bool is##funName(void) const {return varName;}\
	public: void set##funName(bool var){ varName = var;}

// ��Ϣ�ɷ�
#define NOTIFY cocos2d::NotificationCenter::getInstance()
#endif