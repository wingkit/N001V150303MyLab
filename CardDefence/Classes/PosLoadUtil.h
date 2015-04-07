#ifndef _PosLoadUtil_H_
#define _PosLoadUtil_H_
#include "cocos2d.h"
#include "EnumPosType.h"
USING_NS_CC;
class PosBase;
class PosLoadUtil : public Node{
public:
	static PosLoadUtil* getInstance();
	virtual bool init();
	/*
		�����������ʹ�plist�����ļ��ж�ȡ�������
		sFilePath : �����ļ�·��
		enPosType : �����������
		container : ���������������
		iLevel : �������container�� �ò�����ʾ��������������еĲ��
		isDebug : �Ƿ�������ģʽ
	*/
	Vector<PosBase*> loadPosWithFile(
		const char* sFilePath, 
		EnumPosType enPosType,
		Node* container,
		int iLevel,
		bool isDebug);
	/*
		�����������ʹ�json�����ļ��ж�ȡ�������
		key       : ��Ҫ��ȡ�ĸ���ֵ
		sFilePath : �����ļ�·��
		enPosType : �����������
		container : ���������������
		iLevel : �������container�� �ò�����ʾ��������������еĲ��
		isDebug : �Ƿ�������ģʽ
	*/
	Vector<PosBase*> loadPosWithJsonFile(
		const char* key,
		const char* sFilePath, 
		EnumPosType enPosType,
		Node* container,
		int iLevel,
		bool isDebug);
private:
	static PosLoadUtil* m_posLoadUtil;
};
#endif