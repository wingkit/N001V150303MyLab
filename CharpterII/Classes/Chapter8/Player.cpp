#include "Player.h"
#include "WinScene.h"
bool Player::init(){
	isJumping = false;
	return true;
}

void Player::run(){
	SpriteFrameCache* frameCache = SpriteFrameCache::getInstance();
	frameCache->addSpriteFramesWithFile("../Resources/boys.plist", "../Resources/boys.png");

	SpriteFrame* frame = NULL;
	Vector<SpriteFrame*> frameList;

	// 创建精灵帧对象， 添加到列表里
	for(int i = 1; i <= 15; i++){
		frame = frameCache->getSpriteFrameByName(StringUtils::format("run%d.png", i));
		frameList.pushBack(frame);
	}

	// 根据精灵帧对象创建动画对象
	Animation* animation = Animation::createWithSpriteFrames(frameList);
	animation->setLoops(-1); // 循环播放
	animation->setDelayPerUnit(0.08f); // 每帧播放间隔
	// 创建动画动作
	Animate* animate = Animate::create(animation);

	// 精灵执行动作
	m_sprite->runAction(animate);

}

void Player::setViewPointByPlayer(){
	if (m_sprite == NULL) return;
	Layer* parent = (Layer*)getParent();
	// 地图方块数量
	Size mapTiledNum = m_map->getMapSize();

	// 地图单个格子大小
	Size tiledSize = m_map->getTileSize();

	// 地图大小
	Size mapSize = Size(mapTiledNum.width * tiledSize.width, mapTiledNum.height * tiledSize.height);

	// 屏幕大小
	Size visibleSize = Director::getInstance()->getVisibleSize();

	// 主角坐标
	Point spritePos = getPosition();

	// 如果主角坐标小于屏幕一半，则取屏幕中点坐标，否则取主角的坐标
	float x = std::max(spritePos.x, visibleSize.width / 2);
	float y = std::max(spritePos.y, visibleSize.height / 2);

	// 目标点
	Point destPos = Point(x, y);

	// 屏幕中点
	Point centerPos = Point(visibleSize.width /2, visibleSize.height / 2);

	// 计算屏幕中点和所要移动的目的点之间的距离
	Point viewPos = centerPos - destPos;

	parent->setPosition(viewPos);
}

void Player::setTagPosition(int x, int y){
	// 判断前面是否可以通行
	// 取主角前方的坐标
	Size spriteSize = m_sprite->getContentSize();
	Point dstPos = Point(x + spriteSize.width / 2, y);

	// 获取当前主角前方坐标在地图中格子的位置
	Point tiledPos = tileCoordForPosition(Point(dstPos.x, dstPos.y));
	// 获取地图格子的唯一标示
	int tiledGid = meta->getTileGIDAt(tiledPos);

	// 不为0，代表存在这个格子
	if (tiledGid != 0){
		// 获取该地图格子的所有属性，目前我们只有一个Collidable属性属于meta层，
		//但同时也是属于整个地图的，所以在获取格子的所有属性时， 通过格子唯一标示在地图中取得
		Value properties = m_map->getPropertiesForGID(tiledGid);

	

		ValueMap propertiesMap = properties.asValueMap();
		if (propertiesMap.find("Collidable") != propertiesMap.end()){
			// 取得格子的Collidable属性
			Value prop = propertiesMap.at("Collidable");
			// 判断Collidable属性是否为true，如果是，则不让玩家移动
			if(prop.asString().compare("true")==0 && isJumping == false){
				isJumping = true;
				auto jumpBy = JumpBy::create(0.5f, Point(-100,0), 80, 1);
				CallFunc* callFunc = CallFunc::create([&](){
					// 恢复状态
					isJumping = false;
				});
				// 执行动作，碰撞到障碍物时的反弹效果
				auto actions = Sequence::create(jumpBy, callFunc, NULL);
				this->runAction(actions);
			}

		}

		if (propertiesMap.find("food") != propertiesMap.end()){
			// 取得格子的food属性,判断是否为true，如果是，则让格子上的物品消失
			Value prop = propertiesMap.at("food");
			// 判断Collidable属性是否为true，如果是，则不让玩家移动
			if(prop.asString().compare("true")==0){
				// 从障碍物层消除当前格子的物品
				TMXLayer* barrier = m_map->getLayer("barrier");
				barrier->removeTileAt(tiledPos);
			}

		}

		if (propertiesMap.find("win") != propertiesMap.end()){
			Value prop = propertiesMap.at("win");
			if(prop.asString().compare("true")==0){
				Director::getInstance()->replaceScene(WinScene::createScene());	
				Director::getInstance()->end();
			}
		}
		
	}
	Entity::setTagPosition(x, y);
	// 以主角为中心移动地图
	setViewPointByPlayer();
}

void Player::setTiledMap(TMXTiledMap* map){
	this->m_map = map;

	// 保存meta图层的引用
	this->meta = m_map->getLayer("meta");
	this->meta->setVisible(false);
}

Point Player::tileCoordForPosition(Point pos){
	Size mapTiledNum = m_map->getMapSize();
	Size tiledSize = m_map->getTileSize();

	int x = pos.x / tiledSize.width;
	// cocos2d-x 的默认Y坐标是由下至上的， 所以要做一个相减操作
	int y = (700 - pos.y) / tiledSize.height;

	// 格子坐标从零开始计算
	if (x > 0){
		x -= 1;
	}
	if (y >0) {
		y -= 0;
	}
	return Point(x, y);
}