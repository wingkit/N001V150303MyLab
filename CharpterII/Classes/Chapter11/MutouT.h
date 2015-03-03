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
	MutouTFSM* getFSM(); // ��ȡ״̬������
	virtual void update(float dt);

private:
	MutouTFSM* mFSM;
	//State* mCurState; // ��ŵ�ǰ״̬��
};
#endif