#ifndef _Mutou_H_
#define _Mutou_H_
#include "cocos2d.h"
USING_NS_CC;
enum EnumState{
	enStateWriteCode, // 状态：写代码
	enStateWriteArticle,// 状态：写教程
	enStateRest, // 状态：休息
};

class Mutou : public Node{
public:
	CREATE_FUNC(Mutou);
	virtual bool init();

	// 当前状态
	EnumState enCurState; 

	bool isTire();// 判断是否累了
	bool isWantToWriteArticle(); // 是否想写教程

	void writeCode(); // 写代码
	void WriteArticle(); // 写教程
	void rest(); // 休息

	void changeState(EnumState enState); // 切换状态

	virtual void update(float dt);
};
#endif