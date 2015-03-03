#ifndef _CsvData_H_
#define _CsvData_H_
#include "cocos2d.h"
USING_NS_CC;
class CsvData : public Ref{
public:
	CREATE_FUNC(CsvData);
	virtual bool init();

	void addLineData(ValueVector lineData); // 添加一行数据
	ValueVector getSingleLineData(int iLine); // 获取某行数据
	Size getRowColNum(); // 获取行列大小
private:
	// 存放Csv文件所有行的数据， 试试这样理解ValueVector<Value<ValueVector>>
	ValueVector m_allLinesVec;
	int m_iColNum;
};
#endif