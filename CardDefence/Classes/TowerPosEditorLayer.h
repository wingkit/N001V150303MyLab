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

	// ����������������ɵ�pList�����ļ���
	bool outputPosToPlistFile();

	// �л��༭ģʽ
	EnumPosType changeMode();

	// �л�����һ�ؿ�
	int nextLvl();

	// �л�����һ�ؿ�
	int preLvl();

	// ��ȡ���������б�
	Vector<PosBase*> getMonsterPosList();

protected:
private:
	// ������������������
	Vector<PosBase*> m_towerPosList;
	/* ��ָ������������ɵ�plist�����ļ� */
	bool outputPosToPlistFile(Vector<PosBase*> posList, const char* sFilePath);
	/* ��ָ������������ɵ�json�����ļ� */
	bool outputPosToJsonFile(const char* key, Vector<PosBase*> posList, const char* sFilePath);
	// ��ǰ�ؿ�
	int m_iCurLevel;

	// �༭������
	void editTowerPos(Point pos);
	// ���������ҵ��Ѿ����ڵ����������
	PosBase* findExistTowerPos(Point pos);
	// �������꣬�������������
	void createTowerPos(Point pos);
	// ������������� ɾ�����������
	void deleteTowerPos(PosBase* existPos);
	// ɾ�������������
	void deleteAllPos();
	// ��ȡ�����ļ�
	void loadConfigFile();
	// ��ǰģʽ
	EnumPosType m_enMode;
	// �༭��������
	void editMonsterPos(Point pos);
	// ������й�����������
	Vector<PosBase*> m_monsterPosList;

	// ���������ҵ��Ѿ����ڵĹ����������
	PosBase* findExistMonsterPos(Point pos);

	// �������꣬ ���ɹ����������
	void createMonsterPos(Point pos);

	// ��������������� ɾ�������������
	void deleteMonsterPos(PosBase* existPos);
};

#endif