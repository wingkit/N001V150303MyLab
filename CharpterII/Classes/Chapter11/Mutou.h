#ifndef _Mutou_H_
#define _Mutou_H_
#include "cocos2d.h"
USING_NS_CC;
enum EnumState{
	enStateWriteCode, // ״̬��д����
	enStateWriteArticle,// ״̬��д�̳�
	enStateRest, // ״̬����Ϣ
};

class Mutou : public Node{
public:
	CREATE_FUNC(Mutou);
	virtual bool init();

	// ��ǰ״̬
	EnumState enCurState; 

	bool isTire();// �ж��Ƿ�����
	bool isWantToWriteArticle(); // �Ƿ���д�̳�

	void writeCode(); // д����
	void WriteArticle(); // д�̳�
	void rest(); // ��Ϣ

	void changeState(EnumState enState); // �л�״̬

	virtual void update(float dt);
};
#endif