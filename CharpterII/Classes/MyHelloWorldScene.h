/*
    文件名：    MyHelloWorldScene.h
    描　述：    HelloWorld场景
    创建人：    笨木头_钟迪龙 (博客：http://www.benmutou.com)
*/
#ifndef _MyHelloWorldScene_H_
#define _MyHelloWorldScene_H_

#include "cocos2d.h"
using namespace cocos2d;

class MyHelloWorldScene : public Layer {
public:
    /* 通过静态的scene函数，创建一个场景对象 */
    static Scene* createScene();

    /* MyHelloWorldScene的初始化工作都在init里执行 */
    virtual bool init();

    /* 调用宏CREATE_FUNC定义create函数 */
    CREATE_FUNC(MyHelloWorldScene);
};

#endif