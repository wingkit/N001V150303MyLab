#include "NotifyUtil.h"

NotifyUtil* NotifyUtil::m_NotifyUtil = NULL;

NotifyUtil* NotifyUtil::getInstance(){
	if (m_NotifyUtil == NULL){
		m_NotifyUtil = NotifyUtil::create();
		m_NotifyUtil->retain();
	}
	return m_NotifyUtil;
}

bool NotifyUtil::init(){
	return true;
}

void NotifyUtil::addObserver(const std::string &sMsgName, std::function<void(Ref*)> func){
	// 查找是否有已经存在该消息的回调列表
	if (m_funcMap.find(sMsgName) != m_funcMap.end()){
		// 已经存在该回调列表
		std::vector<std::function<void(Ref*)>> &funcList = m_funcMap.at(sMsgName);

		// 将新的订阅者添加到回调列表里
		funcList.push_back(func);

	}else{
		// 不存在该回调列表
		std::vector<std::function<void(Ref*)>> funcLlist;

		// 将新订阅者添加到回调列表里
		funcLlist.push_back(func);

		// 将新建的列表保存到map中
		m_funcMap[sMsgName] = funcLlist;
	}

}

void NotifyUtil::postNotification(const std::string &sMsgName, Ref* data){
	// 查找是否有人订阅过该消息
	if (m_funcMap.find(sMsgName) != m_funcMap.end()){
		// 取得回调列表
		std::vector<std::function<void(Ref*)>> funcList = m_funcMap.at(sMsgName);

		// 遍历列表，回调函数，并传递数据
		for (auto func : funcList){
			func(data);
		}
	}

}