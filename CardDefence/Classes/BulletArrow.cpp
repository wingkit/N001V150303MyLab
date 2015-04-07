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
	// Entity绑定当前精灵
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
	/* 先假想一个场景，一个MapTile，MapTile里有一个主角，主角可以发射子弹，子弹也在背景中。
	现在问题来了，子弹现在的坐标为在背景里的坐标，现在我想判断子弹是否出屏，而背景坐标（世界坐标）
	可能不为0,0，那么我怎么得出子弹在相对与屏幕的坐标呢？可以用子弹当前的坐标减去背景的偏移，
	这是可行的，但如果我处理结构更复杂的坐标转换呢？
	答案是使用2dx框架提供的转换方法，如果是对于上面这个例子，可以这样调用 
	sprite->getParent()->convertToWorldSpace(sprite->getPosition())，其中sprite为子弹精灵的指针，
	getParent()为获取精灵的父结点，convertToWorldSpace()为转换坐标到以此结点为基准的屏幕坐标。
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