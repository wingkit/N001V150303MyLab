/*	
	描述： Csv文件对象
*/
#ifndef _CsvData_H_
#define _CsvData_H_
#include "cocos2d.h"
USING_NS_CC;
class CsvData : public Ref{
public:
	CREATE_FUNC(CsvData);
	virtual bool init();

	// 添加一行数据
	void addLineData(ValueVector lineData);

	// 获取某行的数据
	ValueVector getSingleLineData(int iLine);

	// 获取行列大小
	Size getRowColNum();
private:
	// 存放Csv文件所有行的数据， 试试这样理解：ValueVector<Value<ValueVector> >
	ValueVector m_allLinesVec;
};
#endif