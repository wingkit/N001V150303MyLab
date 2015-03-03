#ifndef _MutouT_H_
#define _MutouT_H_
#include "State.h"
#include "cocos2d.h"
USING_NS_CC;
class MutouTFSM;
class MutouT : public Node{
public:
	CREATE_FUNC(MutouT);
	virtual bool init();

	bool isTire();
	bool isWantToWriteArticle();
	void writeCode();
	void writeArticle();
	void rest();
	//void changeState(State* state);
	MutouTFSM* getFSM(); // 获取状态机对象
	virtual void update(float dt);

private:
	MutouTFSM* mFSM;
	//State* mCurState; // 存放当前状态类
};
#endif