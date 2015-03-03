#include "OtherLayer.h"

bool OtherLayer::init(){
	if (!Layer::init()) return false;

	// ������Ϣ����Ϊtest����Ϣ�� ����������
	NotificationCenter::getInstance()->addObserver(
		this, 
		callfuncO_selector(OtherLayer::testMsg),
		"test",
		NULL);
		//(Ref*)"OtherLayer's data");
	return true;
}

void OtherLayer::testMsg(Ref* pData){
	log("testMsg in OtherLayer : %s", pData);
}