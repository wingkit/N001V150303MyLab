#include "HelloLua.h"

Scene* HelloLua::createScene(){
	auto scene = Scene::create();
	auto layer = HelloLua::create();
	scene->addChild(layer);
	return scene;
}

bool HelloLua::init(){
	lua_State* pL = lua_open();
	luaopen_base(pL);
	luaopen_math(pL);
	luaopen_string(pL);

	// 1.执行Lua脚本，返回0表示成功
	int err = luaL_dofile(pL, "../Resources/helloLua.lua");
	log("open : %d", err);

	// 2.重置栈顶索引
	lua_settop(pL, 0);
	lua_getglobal(pL, "myName");

	// 3.判断栈顶的值的类型是否为string，返回非0代表成功
	int isstr = lua_isstring(pL, 1);
	log("isstr = %d", isstr);

	// 4.获取栈顶的值
	if(isstr != 0){
		const char* str = lua_tostring(pL, 1);
		log("getStr = %s", str);
	}

	lua_close(pL);
	return true;
}