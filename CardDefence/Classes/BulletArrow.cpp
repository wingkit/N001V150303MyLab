#include "BulletArrow.h"
#include "ControllerSimpleMove.h"
#include "GlobalPath.h"

BulletArrow::BulletArrow(){
	m_iSpeed = SPEED_NORMAL;
}

BulletArrow::~BulletArrow(){

}

BulletArrow* BulletArrow::create(Sprite* sprite){
	BulletArrow* bulletArrow = new BulletArrow();

	if (bulletArrow && bulletArrow->init(sprite)){
		bulletArrow->autorelease();
	} else {
		CC_SAFE_DELETE(bulletArrow);
	}

	return bulletArrow;
}

bool BulletArrow::init(Sprite* sprite){
	// Entity�󶨵�ǰ����
	bindSprite(sprite);

	return true;
}

bool BulletArrow::init(){
	bool bRet = false;

	do {
		Sprite* sprite = Sprite::create(PATH_BULLET_ARR);
		CC_BREAK_IF(!sprite);
		CC_BREAK_IF(!init(sprite));

		bRet = true;
	}while(0);
	return bRet;
}

void BulletArrow::onLockAim(Entity* aim){
	m_isArrive = false;
	/************************************************************************/
	/* �ȼ���һ��������һ��MapTile��MapTile����һ�����ǣ����ǿ��Է����ӵ����ӵ�Ҳ�ڱ����С�
	�����������ˣ��ӵ����ڵ�����Ϊ�ڱ���������꣬���������ж��ӵ��Ƿ���������������꣨�������꣩
	���ܲ�Ϊ0,0����ô����ô�ó��ӵ����������Ļ�������أ��������ӵ���ǰ�������ȥ������ƫ�ƣ�
	���ǿ��еģ�������Ҵ���ṹ�����ӵ�����ת���أ�
	����ʹ��2dx����ṩ��ת������������Ƕ�������������ӣ������������� 
	sprite->getParent()->convertToWorldSpace(sprite->getPosition())������spriteΪ�ӵ������ָ�룬
	getParent()Ϊ��ȡ����ĸ���㣬convertToWorldSpace()Ϊת�����굽�Դ˽��Ϊ��׼����Ļ���ꡣ
	*/
	/************************************************************************/
	Point aimWorldPos = aim->getParent()->convertToWorldSpace(aim->getPosition());
	Point dstPos = this->getParent()->convertToNodeSpace(aimWorldPos);
	auto moveTo = MoveTo::create(0.5f, dstPos);
	auto callFunc = CallFunc::create([&](){
		moveEnd();
	});

	auto actions = Sequence::create(moveTo, callFunc, NULL);
	this->runAction(actions);
}

void BulletArrow::moveEnd(){
	m_isArrive = true;
}