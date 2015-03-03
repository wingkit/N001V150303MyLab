#ifndef _NotifyUtil_H_
#define _NotifyUtil_H_
#include "cocos2d.h"
USING_NS_CC;
class NotifyUtil : public Ref{
public:
	static NotifyUtil* getInstance();
	CREATE_FUNC(NotifyUtil);
	virtual bool init();

	// ������Ϣ
	void addObserver(const std::string& sMsgName, std::function<void(Ref*)> func);

	// ������Ϣ
	void postNotification(const std::string& sMsgName, Ref* data);

private:
	static NotifyUtil* m_NotifyUtil;

	// �������ܸ��ӣ���ʵ�ܼ�
	std::map<std::string, std::vector<std::function<void(Ref*)>>> m_funcMap;
};
#endif