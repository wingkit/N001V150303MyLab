#ifndef _GlobalDefine_H_
#define _GlobalDefine_H_
#include "cocos2d.h"
// #���ַ����� ##��һ�����ӷ�
// ����bool������ ����get��set����
<<<<<<< HEAD
#define CC_SYNTHESIZE_BOOL(varName, funName)\
	protected: bool varName; \
	public: bool is##funName(void) const {return varName;}\
	public: void set##funName(bool var){ varName = var;}
=======
#define CC_CC_SYNTHESIZE_BOOL(varName, funcName)\
	protected: bool varName; \
	public: bool is##funName(void) const {return varName;}\
	public: void set##funcName(bool var){ varName = var;}
>>>>>>> 242d9fd9e2218bb56c21948853acb0e3a3cae294

// ��Ϣ�ɷ�
#define NOTIFY cocos2d::NotificationCenter::getInstance()
#endif