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

	// ��������֡���� ��ӵ��б���
	for(int i = 1; i <= 15; i++){
		frame = frameCache->getSpriteFrameByName(StringUtils::format("run%d.png", i));
		frameList.pushBack(frame);
	}

	// ���ݾ���֡���󴴽���������
	Animation* animation = Animation::createWithSpriteFrames(frameList);
	animation->setLoops(-1); // ѭ������
	animation->setDelayPerUnit(0.08f); // ÿ֡���ż��
	// ������������
	Animate* animate = Animate::create(animation);

	// ����ִ�ж���
	m_sprite->runAction(animate);

}

void Player::setViewPointByPlayer(){
	if (m_sprite == NULL) return;
	Layer* parent = (Layer*)getParent();
	// ��ͼ��������
	Size mapTiledNum = m_map->getMapSize();

	// ��ͼ�������Ӵ�С
	Size tiledSize = m_map->getTileSize();

	// ��ͼ��С
	Size mapSize = Size(mapTiledNum.width * tiledSize.width, mapTiledNum.height * tiledSize.height);

	// ��Ļ��С
	Size visibleSize = Director::getInstance()->getVisibleSize();

	// ��������
	Point spritePos = getPosition();

	// �����������С����Ļһ�룬��ȡ��Ļ�е����꣬����ȡ���ǵ�����
	float x = std::max(spritePos.x, visibleSize.width / 2);
	float y = std::max(spritePos.y, visibleSize.height / 2);

	// Ŀ���
	Point destPos = Point(x, y);

	// ��Ļ�е�
	Point centerPos = Point(visibleSize.width /2, visibleSize.height / 2);

	// ������Ļ�е����Ҫ�ƶ���Ŀ�ĵ�֮��ľ���
	Point viewPos = centerPos - destPos;

	parent->setPosition(viewPos);
}

void Player::setTagPosition(int x, int y){
	// �ж�ǰ���Ƿ����ͨ��
	// ȡ����ǰ��������
	Size spriteSize = m_sprite->getContentSize();
	Point dstPos = Point(x + spriteSize.width / 2, y);

	// ��ȡ��ǰ����ǰ�������ڵ�ͼ�и��ӵ�λ��
	Point tiledPos = tileCoordForPosition(Point(dstPos.x, dstPos.y));
	// ��ȡ��ͼ���ӵ�Ψһ��ʾ
	int tiledGid = meta->getTileGIDAt(tiledPos);

	// ��Ϊ0����������������
	if (tiledGid != 0){
		// ��ȡ�õ�ͼ���ӵ��������ԣ�Ŀǰ����ֻ��һ��Collidable��������meta�㣬
		//��ͬʱҲ������������ͼ�ģ������ڻ�ȡ���ӵ���������ʱ�� ͨ������Ψһ��ʾ�ڵ�ͼ��ȡ��
		Value properties = m_map->getPropertiesForGID(tiledGid);

	

		ValueMap propertiesMap = properties.asValueMap();
		if (propertiesMap.find("Collidable") != propertiesMap.end()){
			// ȡ�ø��ӵ�Collidable����
			Value prop = propertiesMap.at("Collidable");
			// �ж�Collidable�����Ƿ�Ϊtrue������ǣ���������ƶ�
			if(prop.asString().compare("true")==0 && isJumping == false){
				isJumping = true;
				auto jumpBy = JumpBy::create(0.5f, Point(-100,0), 80, 1);
				CallFunc* callFunc = CallFunc::create([&](){
					// �ָ�״̬
					isJumping = false;
				});
				// ִ�ж�������ײ���ϰ���ʱ�ķ���Ч��
				auto actions = Sequence::create(jumpBy, callFunc, NULL);
				this->runAction(actions);
			}

		}

		if (propertiesMap.find("food") != propertiesMap.end()){
			// ȡ�ø��ӵ�food����,�ж��Ƿ�Ϊtrue������ǣ����ø����ϵ���Ʒ��ʧ
			Value prop = propertiesMap.at("food");
			// �ж�Collidable�����Ƿ�Ϊtrue������ǣ���������ƶ�
			if(prop.asString().compare("true")==0){
				// ���ϰ����������ǰ���ӵ���Ʒ
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
	// ������Ϊ�����ƶ���ͼ
	setViewPointByPlayer();
}

void Player::setTiledMap(TMXTiledMap* map){
	this->m_map = map;

	// ����metaͼ�������
	this->meta = m_map->getLayer("meta");
	this->meta->setVisible(false);
}

Point Player::tileCoordForPosition(Point pos){
	Size mapTiledNum = m_map->getMapSize();
	Size tiledSize = m_map->getTileSize();

	int x = pos.x / tiledSize.width;
	// cocos2d-x ��Ĭ��Y�������������ϵģ� ����Ҫ��һ���������
	int y = (700 - pos.y) / tiledSize.height;

	// ����������㿪ʼ����
	if (x > 0){
		x -= 1;
	}
	if (y >0) {
		y -= 0;
	}
	return Point(x, y);
}