#ifndef _CsvUtil_H_
#define _CsvUtil_H_
#include "cocos2d.h"
#include "CsvData.h"
USING_NS_CC;
class CsvUtil : public Ref{
public:
	static CsvUtil* getInstance();
	virtual bool init();

	void loadFile(const char* sPath); // 加载配置文件

	Value getValue(int iRow, int iCol, const char* csvFilePath); // 获取某行某列的值
	const std::string get(int iRow, int iCol, const char* csvFilePath); // 获取值并转换为字符串
	const int getInt(int iRow, int iCol, const char* csvFilePath); // 获取值并转换为整型
	const float getFloat(int iRow, int iCol, const char* csvFilePath); // 获取值并转换为整型
	const bool getBool(int iRow, int iCol, const char* csvFilePath); // 获取值并转换为整型
	const Size getFileRowColNum(const char* csvFilePath); // 获取文件的行列数量

	// 根据某个列的值，查找该值所在的行
	const int findValueInWithLine(const char* chValue, int iValueCol, const char* csvFilePath);
private:
	static CsvUtil* m_CsvUtil;
	Map<std::string, CsvData*> mCsvMap; // 存放mCsvStrList-filePath的字典
};
#endif