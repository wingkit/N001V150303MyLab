#ifndef _CsvUtil_H_
#define _CsvUtil_H_
#include "cocos2d.h"
#include "CsvData.h"
USING_NS_CC;
class CsvUtil : public Ref{
public:
	static CsvUtil* getInstance();
	virtual bool init();

	void loadFile(const char* sPath); // ���������ļ�

	Value getValue(int iRow, int iCol, const char* csvFilePath); // ��ȡĳ��ĳ�е�ֵ
	const std::string get(int iRow, int iCol, const char* csvFilePath); // ��ȡֵ��ת��Ϊ�ַ���
	const int getInt(int iRow, int iCol, const char* csvFilePath); // ��ȡֵ��ת��Ϊ����
	const float getFloat(int iRow, int iCol, const char* csvFilePath); // ��ȡֵ��ת��Ϊ����
	const bool getBool(int iRow, int iCol, const char* csvFilePath); // ��ȡֵ��ת��Ϊ����
	const Size getFileRowColNum(const char* csvFilePath); // ��ȡ�ļ�����������

	// ����ĳ���е�ֵ�����Ҹ�ֵ���ڵ���
	const int findValueInWithLine(const char* chValue, int iValueCol, const char* csvFilePath);
private:
	static CsvUtil* m_CsvUtil;
	Map<std::string, CsvData*> mCsvMap; // ���mCsvStrList-filePath���ֵ�
};
#endif