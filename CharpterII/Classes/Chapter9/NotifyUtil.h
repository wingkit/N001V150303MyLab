#ifndef _NotifyUtil_H_
#define _NotifyUtil_H_
#include "cocos2d.h"
USING_NS_CC;
class NotifyUtil : public Ref{
public:
	static NotifyUtil* getInstance();
	CREATE_FUNC(NotifyUtil);
	virtual bool init();

	// 订阅消息
	void addObserver(const std::string& sMsgName, std::function<void(Ref*)> func);

	// 发布消息
	void postNotification(const std::string& sMsgName, Ref* data);

private:
	static NotifyUtil* m_NotifyUtil;

	// 看起来很复杂，其实很简单
	std::map<std::string, std::vector<std::function<void(Ref*)>>> m_funcMap;
};
#endif