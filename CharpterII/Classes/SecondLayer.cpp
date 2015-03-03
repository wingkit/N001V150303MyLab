#include "SecondLayer.h"

SecondLayer::SecondLayer(){}
SecondLayer::~SecondLayer(){}
bool SecondLayer::init(){
	if (!Layer::init()){return false;}

	auto sprite3 = Sprite::create("../Resources/sprite0.png");
	sprite3->setPosition(Point(240, 160));
	this->addChild(sprite3);
	return true;
}