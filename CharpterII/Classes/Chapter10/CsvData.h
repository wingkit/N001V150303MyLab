#ifndef _CsvData_H_
#define _CsvData_H_
#include "cocos2d.h"
USING_NS_CC;
class CsvData : public Ref{
public:
	CREATE_FUNC(CsvData);
	virtual bool init();

	void addLineData(ValueVector lineData); // ���һ������
	ValueVector getSingleLineData(int iLine); // ��ȡĳ������
	Size getRowColNum(); // ��ȡ���д�С
private:
	// ���Csv�ļ������е����ݣ� �����������ValueVector<Value<ValueVector>>
	ValueVector m_allLinesVec;
	int m_iColNum;
};
#endif