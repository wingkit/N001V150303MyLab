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
	// �����Ƿ����Ѿ����ڸ���Ϣ�Ļص��б�
	if (m_funcMap.find(sMsgName) != m_funcMap.end()){
		// �Ѿ����ڸûص��б�
		std::vector<std::function<void(Ref*)>> &funcList = m_funcMap.at(sMsgName);

		// ���µĶ�������ӵ��ص��б���
		funcList.push_back(func);

	}else{
		// �����ڸûص��б�
		std::vector<std::function<void(Ref*)>> funcLlist;

		// ���¶�������ӵ��ص��б���
		funcLlist.push_back(func);

		// ���½����б��浽map��
		m_funcMap[sMsgName] = funcLlist;
	}

}

void NotifyUtil::postNotification(const std::string &sMsgName, Ref* data){
	// �����Ƿ����˶��Ĺ�����Ϣ
	if (m_funcMap.find(sMsgName) != m_funcMap.end()){
		// ȡ�ûص��б�
		std::vector<std::function<void(Ref*)>> funcList = m_funcMap.at(sMsgName);

		// �����б��ص�����������������
		for (auto func : funcList){
			func(data);
		}
	}

}