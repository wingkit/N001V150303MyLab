#ifndef _MutouTFSM_H_
#define _MutouTFSM_H_
#include "cocos2d.h"
#include "MutouT.h"
#include "State.h"
USING_NS_CC;

class MutouTFSM : public Node{
public:
	~MutouTFSM();
	static MutouTFSM* createWithMutouT(MutouT* mutou);
	bool initWithMutouT(MutouT* mutou);

	//virtual void update(float dt);
	void changeState(State* state); // ÇÐ»»×´Ì¬
private:
	void onRecvWantToRest(Ref* obj);
	void onRecvWantToWriteCode(Ref* obj);
	void onRecvWantToWriteAritcle(Ref* obj);
	State* mCurState;
	MutouT* mMutou;
};
#endif