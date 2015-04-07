/*
	������ ���ʻ����ߣ���Ϸ����˵����
*/
#ifndef _I18N_H_
#define _I18N_H_
#include "cocos2d.h"
#include "EnumStrKey.h"
using namespace cocos2d;

class I18N : public Ref{
public:
	// ��ȡ����
	static I18N* getInstance();

	// ��ʼ��
	virtual bool init();

	// ����Keyֵ��ȡ�ַ���������const char* ����
	const char* getcString(EnumStrKey enStrKey);

	// �������͵�Keyֵ��ȡ�ַ���������const char* ����
	const char* getcStringByKey(int iKey);

private:
	// �������ļ��ж�ȡ�ַ��������浽�ֵ���
	void loadStringsFromConf( const char* filePath);

	// I18N����
	static I18N* m_I18N;

	// ��Ϸ���õ����ַ����ֵ�
	std::map<int, std::string> mStringMap;
};
#endif