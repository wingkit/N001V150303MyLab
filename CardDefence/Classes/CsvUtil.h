/*	
	描述： Csv文件读取工具
*/
#ifndef _CsvUtil_H_
#define _CsvUtil_H_
#include "cocos2d.h"
#include "CsvData.h"
using namespace std;

class CsvUtil : public Ref{
public:
	// 获取工具对象
	static CsvUtil* getInstance();

	virtual bool init();
	// 加载配置文件
	void loadFile(const char* sPath);

	// 获取某行某列的值
	Value getValue(int iRow, int iCol, const char* csvFilePath);

	// 获取某行某列的值，并转化为字符串
	const std::string get(int iRow, int iCol, const char* csvFilePath);

	// 获取某行某列的值，并转化为整数
	const int getInt(int iRow, int iCol, const char* csvFilePath);

	// 获取某行某列的值，并转化为浮点型
	const float getFloat(int iRow, int iCol, const char* csvFilePath);

	// 获取某行某列的值，并转化为布尔型
	const bool getBool(int iRow, int iCol, const char* csvFilePath);

	// 获取配置文件数据的行和列数量
	const Size getFileRowColNum(const char* csvFilePath);

	// 根据某个列的值，查找该值所在的行
	const int findValueInWithLine(const char* chValue, int iValueCol, const char* csvFilePath);

private:
	static CsvUtil* m_CsvUtil;

	// 存放mCsvStrList-filePath的字典
	Map<std::string, CsvData*> mCsvMap;
};
#endif