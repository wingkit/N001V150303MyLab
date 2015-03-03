#include "StringUtil.h"
StringUtil* StringUtil::m_StringUtil = NULL;
StringUtil* StringUtil::getInstance(){
	if (m_StringUtil == NULL){
		m_StringUtil = new StringUtil();
		if (m_StringUtil && m_StringUtil->init()){
			m_StringUtil->autorelease();
			m_StringUtil->retain();
		} else {
			CC_SAFE_DELETE(m_StringUtil);
			m_StringUtil = NULL;
		}
	}
	return m_StringUtil;
}

bool StringUtil::init(){
	return true;
}

ValueVector StringUtil::split(const char* srcStr, const char* sSep){
	ValueVector stringList; // vector<Value>
	int size = strlen(srcStr);

	// 将数据转换为字符串对象
	Value str = Value(srcStr);

	int startIndex = 0;
	int endIndex = 0;
	endIndex = str.asString().find(sSep);

	std::string lineStr;
	// 根据换行符分隔字符串， 并添加到列表中
	while (endIndex > 0){
		lineStr = str.asString().substr(startIndex, endIndex); // 截取一行字符串
		stringList.push_back(Value(lineStr));				   // 添加到列表
		str = Value(str.asString().substr(endIndex+1, size));  // 截取剩下的字符串

		endIndex = str.asString().find(sSep);
	}

	// 剩下的字符串也添加到列表
	if (str.asString().compare("") != 0){
		stringList.push_back(Value(str.asString()));
	}
	return stringList;
}