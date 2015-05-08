#ifndef _TowerPosEditorLayer_H_
#define _TowerPosEditorLayer_H_
#include "cocos2d.h"
#include "PosBase.h"
#include "EnumPosType.h"
USING_NS_CC;
class TowerPosEditorLayer : public Layer{
public:
	TowerPosEditorLayer();
	~TowerPosEditorLayer();
	CREATE_FUNC(TowerPosEditorLayer);
	virtual bool init();

	// 把所有坐标对象生成到pList配置文件中
<<<<<<< HEAD
	bool outputPosToPlistFile();

	// 切换编辑模式
	EnumPosType changeMode();
=======
	void outputPosToPlistFile();

	// 切换编辑模式
	void changeMode();
>>>>>>> 242d9fd9e2218bb56c21948853acb0e3a3cae294

	// 切换到下一关卡
	int nextLvl();

	// 切换到上一关卡
	int preLvl();

	// 获取怪物坐标列表
	Vector<PosBase*> getMonsterPosList();

protected:
private:
	// 存放所有塔的坐标对象
	Vector<PosBase*> m_towerPosList;
	/* 把指定坐标对象生成到plist配置文件 */
<<<<<<< HEAD
	bool outputPosToPlistFile(Vector<PosBase*> posList, const char* sFilePath);
	/* 把指定坐标对象生成到json配置文件 */
	bool outputPosToJsonFile(const char* key, Vector<PosBase*> posList, const char* sFilePath);
=======
	void outputPosToPlistFile(Vector<PosBase*> posList, const char* sFilePath);
>>>>>>> 242d9fd9e2218bb56c21948853acb0e3a3cae294
	// 当前关卡
	int m_iCurLevel;

	// 编辑塔坐标
	void editTowerPos(Point pos);
	// 根据坐标找到已经存在的塔坐标对象
	PosBase* findExistTowerPos(Point pos);
	// 给定坐标，生成塔坐标对象
	void createTowerPos(Point pos);
	// 给定塔坐标对象， 删除塔坐标对象
	void deleteTowerPos(PosBase* existPos);
	// 删除所有坐标对象
	void deleteAllPos();
	// 读取配置文件
	void loadConfigFile();
	// 当前模式
	EnumPosType m_enMode;
	// 编辑怪物坐标
	void editMonsterPos(Point pos);
	// 存放所有怪物的坐标对象
	Vector<PosBase*> m_monsterPosList;

	// 根据坐标找到已经存在的怪物坐标对象
	PosBase* findExistMonsterPos(Point pos);

	// 给定坐标， 生成怪物坐标对象
	void createMonsterPos(Point pos);

	// 给定怪物坐标对象， 删除怪物坐标对象
	void deleteMonsterPos(PosBase* existPos);
};

#endif