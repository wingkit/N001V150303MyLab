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
	// ��������Ƿ���ײ���ϰ�� �ڷ�����
	bool isJumping;

	// �����ײ��ͼ��
	TMXLayer* meta;

	// ����������ת��Ϊ��ͼ��������
	Point tileCoordForPosition(Point pos);
};

#endif