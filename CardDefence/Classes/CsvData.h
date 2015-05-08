/*	
	������ Csv�ļ�����
*/
#ifndef _CsvData_H_
#define _CsvData_H_
#include "cocos2d.h"
USING_NS_CC;
class CsvData : public Ref{
public:
	CREATE_FUNC(CsvData);
	virtual bool init();

	// ���һ������
	void addLineData(ValueVector lineData);

	// ��ȡĳ�е�����
	ValueVector getSingleLineData(int iLine);

	// ��ȡ���д�С
	Size getRowColNum();
private:
	// ���Csv�ļ������е����ݣ� ����������⣺ValueVector<Value<ValueVector> >
	ValueVector m_allLinesVec;
};
#endif