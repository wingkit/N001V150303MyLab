#ifndef _Player_H__
#define _Player_H__
#include "Entity.h"
class Player : public Entity{
public:
	CREATE_FUNC(Player);
	virtual bool init();
	void run();
	void setViewPointByPlayer();
	virtual void setTagPosition(int x, int y);
	void setTiledMap(TMXTiledMap* map);
private:
	TMXTiledMap* m_map;
	// 标记主角是否碰撞了障碍物， 在反弹中
	bool isJumping;

	// 检测碰撞地图层
	TMXLayer* meta;

	// 将像素坐标转化为地图格子坐标
	Point tileCoordForPosition(Point pos);
};

#endif