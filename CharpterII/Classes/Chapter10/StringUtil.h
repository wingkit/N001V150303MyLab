#ifndef _StringUtil_H_
#define _StringUtil_H_
#include "cocos2d.h"
using namespace cocos2d;
class StringUtil : public Ref{
public:
	static StringUtil* getInstance();
	virtual bool init();

	// �÷ָ����ָ��ַ����������ŵ�һ���б��У��б��еĶ���ΪValue
	ValueVector split(const char* srcStr, const char* sSep);
private:
	static StringUtil* m_StringUtil;
};
#endif