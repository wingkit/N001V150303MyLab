#ifndef _PosLoadUtil_H_
#define _PosLoadUtil_H_
#include "cocos2d.h"
#include "EnumPosType.h"
USING_NS_CC;
class PosBase;
class PosLoadUtil : public Node{
public:
	static PosLoadUtil* getInstance();
	virtual bool init();
	/*
		根据坐标类型从plist配置文件中读取坐标对象
		sFilePath : 配置文件路径
		enPosType : 坐标对象类型
		container : 存放坐标对象的容器
		iLevel : 如果存在container， 该参数表示坐标对象在容器中的层次
		isDebug : 是否开启调试模式
	*/
	Vector<PosBase*> loadPosWithFile(
		const char* sFilePath, 
		EnumPosType enPosType,
		Node* container,
		int iLevel,
		bool isDebug);
<<<<<<< HEAD
	/*
		根据坐标类型从json配置文件中读取坐标对象
		key       : 需要获取的根键值
		sFilePath : 配置文件路径
		enPosType : 坐标对象类型
		container : 存放坐标对象的容器
		iLevel : 如果存在container， 该参数表示坐标对象在容器中的层次
		isDebug : 是否开启调试模式
	*/
	Vector<PosBase*> loadPosWithJsonFile(
		const char* key,
		const char* sFilePath, 
		EnumPosType enPosType,
		Node* container,
		int iLevel,
		bool isDebug);
=======
>>>>>>> 242d9fd9e2218bb56c21948853acb0e3a3cae294
private:
	static PosLoadUtil* m_posLoadUtil;
};
#endif