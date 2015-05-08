#ifndef _SceneManager_H_
#define _SceneManager_H_
#include "cocos2d.h"
using namespace cocos2d;
class SceneManager : public Ref{
public:
	// ����ö����
	enum EnumSceneType{
		en_TollgateScene, // �ؿ�����
		en_TollgateEditorScene, // �ؿ��༭������
		en_WinScene, // ʤ������
		en_GameOverScene, // ��Ϸ��������
<<<<<<< HEAD
		en_TollgateSelectScene, // �ؿ�ѡ�񳡾�
		en_TollgateStartScene, // ��ʼ����
=======
>>>>>>> 242d9fd9e2218bb56c21948853acb0e3a3cae294
	};
	// ��ȡ��������������
	static SceneManager* getInstance();
	// ��ʼ��
	virtual bool init();
	// �л�����
	void changeScene(EnumSceneType enSceneType);
private:

	// ��������������
	static SceneManager* mSceneManager;
};
#endif