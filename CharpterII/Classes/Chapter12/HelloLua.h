#ifndef _HelloLua_H_
#define _HelloLua_H_

extern "C"{
#include <lua.h>
#include <lualib.h>
#include <lauxlib.h>
};
#include "cocos2d.h"
USING_NS_CC;
class HelloLua : public Layer{
public:
	CREATE_FUNC(HelloLua);
	virtual bool init();
	static Scene* createScene();
};
#endif