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

	// 1.ִ��Lua�ű�������0��ʾ�ɹ�
	int err = luaL_dofile(pL, "../Resources/helloLua.lua");
	log("open : %d", err);

	// 2.����ջ������
	lua_settop(pL, 0);
	lua_getglobal(pL, "myName");

	// 3.�ж�ջ����ֵ�������Ƿ�Ϊstring�����ط�0����ɹ�
	int isstr = lua_isstring(pL, 1);
	log("isstr = %d", isstr);

	// 4.��ȡջ����ֵ
	if(isstr != 0){
		const char* str = lua_tostring(pL, 1);
		log("getStr = %s", str);
	}

	lua_close(pL);
	return true;
}