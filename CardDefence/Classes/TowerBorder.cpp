#include "TowerBorder.h"
#include "Hero.h"
#include "AnimationUtil.h"

TowerBorder::TowerBorder(){
	m_iLevel = 1;
	m_hero = NULL;
	m_cancelBtn = NULL;
	m_deleteBtn = NULL;
	m_upgradeBtn = NULL;
	m_isOprBtnsShow = false;
}

TowerBorder::~TowerBorder(){

}

bool TowerBorder::init(){
	return true;
}

void TowerBorder::upgrade(){
	// 升级炮塔的时候先停止该炮塔的动作
	if (getSprite() != NULL){
		getSprite()->stopAllActions();
	}

	std::string sFilePath = StringUtils::format("sprite/hero/border_%d.png", m_iLevel);
	Sprite* sprite = Sprite::create(sFilePath.c_str());

	bindSprite(sprite);
	sprite->setOpacity(0);

	// 炮台等级 一开始初始化是1级
	m_iLevel++;

	if (m_iLevel == 2){
		sFilePath = StringUtils::format("sprite/hero/magic_border_%d.png", m_iLevel);
		sprite = Sprite::create(sFilePath.c_str());
		//auto rotateBy = RotateBy::create(25.0f, 360, 360);// 旋转
		//auto repeat = RepeatForever::create(rotateBy); // 无限重复
		//sprite->runAction(repeat);
		//sprite->setRotation3D(Vec3(20, 20, 20));// 倾斜
		this->addChild(sprite, 10);

		// 加载图片帧到缓存池
		SpriteFrameCache* frameCache = SpriteFrameCache::getInstance();
		frameCache->addSpriteFramesWithFile("sprite/hero/magic_border.plist", "sprite/hero/magic_border.png");
		// 使用辅助工具创建动画
		Animation* animation = AnimationUtil::creaateWithSingleFrameName("magic_border_", 0.1f, -1);
		sprite->runAction(Animate::create(animation));
		sprite->setOpacity(180);
		
		

	}
}

// 根据左上方与右下方的两点，确定点击的坐标是否在当前矩形上
bool TowerBorder::isClickMe(Point pos){
	Size size = getSprite()->getContentSize();
	// 塔的中点
	Point borderPos = getPosition();
	// 左上角位置
	Point uLeftPos = Point(borderPos.x - size.width / 2, borderPos.y + size.height / 2);
	// 右下角位置
	Point dRightPos = Point(borderPos.x + size.width / 2, borderPos.y - size.height / 2 );

	if ( uLeftPos.x <= pos.x && pos.x <= dRightPos.x 
		&& dRightPos.y <= pos.y && pos.y <= uLeftPos.y){
		return true;
	}

	return false;
}

void TowerBorder::bindHero(Hero* hero){
	m_hero = hero;
}

Hero* TowerBorder::getHero(){
	return m_hero;
}

void TowerBorder::deleteHero(){
	if (m_hero != NULL){
		m_hero->removeFromParent();
	}
}

void TowerBorder::showTowerOprBtns(){
	if (m_isOprBtnsShow == true){
		// 已经是显示状态
		return;
	}

	if (m_cancelBtn == NULL){
		// 手动创建一个按钮
		auto heroOprBtn = Button::create();
		heroOprBtn->loadTextureNormal("button2.png");

		// 用过clone函数复制三个按钮对象
		m_cancelBtn = (Button*)heroOprBtn->clone();
		m_deleteBtn = (Button*)heroOprBtn->clone();
		m_upgradeBtn = (Button*)heroOprBtn->clone();

		// 初始化按钮位置
		resetOprBtns();

		m_cancelBtn->setTitleText("cancel");
		m_deleteBtn->setTitleText("delete");
		m_upgradeBtn->setTitleText("upgrade");

		m_cancelBtn->addTouchEventListener(this, toucheventselector(TowerBorder::cancelClick));
		m_deleteBtn->addTouchEventListener(this, toucheventselector(TowerBorder::deleteClick));
		m_upgradeBtn->addTouchEventListener(this, toucheventselector(TowerBorder::upgradeClick));

		this->addChild(m_cancelBtn, 9999);
		this->addChild(m_deleteBtn, 99999);
		this->addChild(m_upgradeBtn, 999);

		vecOprBtns.pushBack(m_cancelBtn);
		vecOprBtns.pushBack(m_deleteBtn);
		vecOprBtns.pushBack(m_upgradeBtn);
	}

	m_isOprBtnsShow = true;
	for (auto oprBtn : vecOprBtns){
		oprBtn->setEnabled(true);
		oprBtn->setVisible(true);
	}

	// 按钮出场特效
	m_cancelBtn->runAction(EaseBounceOut::create(MoveBy::create(0.5f, Point(0, 100))));
	m_deleteBtn->runAction(EaseBounceOut::create(MoveBy::create(0.5f, Point(-100, 0))));
	m_upgradeBtn->runAction(EaseBounceOut::create(MoveBy::create(0.5f, Point(100, 0))));

	
}

void TowerBorder::deleteOprBtns(){
	if (m_cancelBtn != NULL){
	
		for (auto oprBtn : vecOprBtns){
			oprBtn->setEnabled(false);
			oprBtn->setVisible(false);
		}

		resetOprBtns();
	}

	m_isOprBtnsShow = false;
}

void TowerBorder::resetOprBtns(){
	// 让按钮恢复到中点的位置
	Size size = this->getContentSize();
	Point pos = Point(0, 0);
	m_cancelBtn->setPosition(pos);
	m_deleteBtn->setPosition(pos);
	m_upgradeBtn->setPosition(pos);
}

void TowerBorder::cancelClick(Ref* target, TouchEventType type){
	if (type == TouchEventType::TOUCH_EVENT_ENDED){
		deleteOprBtns();
	}
}

void TowerBorder::deleteClick(Ref* target, TouchEventType type){
	if (type == TouchEventType::TOUCH_EVENT_ENDED){
		deleteHero();
		m_hero = NULL;

		deleteOprBtns();
	}
}

void TowerBorder::upgradeClick(Ref* target, TouchEventType type){
	if (type == TouchEventType::TOUCH_EVENT_ENDED){
		m_hero->upgrade();

		deleteOprBtns();
	}
}
