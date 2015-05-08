#include "Entity.h"

Entity::Entity(){
	m_sprite = NULL;
	m_sName = "";
	m_iHP = 1;
	m_iDefense = 1;
	m_isDead = false;
	m_iSpeed = 1;
	m_iLevel = 1;
}

Entity::~Entity(){

}

void Entity::bindSprite(Sprite* sprite){
	if (this->m_sprite != NULL){
		m_sprite->removeFromParentAndCleanup(true);
	}

	this->m_sprite = sprite;
	this->addChild(m_sprite);

	Size size = m_sprite->getContentSize();
	this->setContentSize(size);

	onBindSprite();
}

Sprite* Entity::getSprite(){
	return this->m_sprite;
}

void Entity::hurtMe(int iHurtValue){
<<<<<<< HEAD
	if (m_isDead 
		|| m_sprite == NULL 
		|| m_iHP == 0 || m_ID == 0 || m_iModelID == 0 || m_iSpeed == 0){
		if (m_iHP == 0) log("monster's hp is zero, hurtMe return;");
		if (m_ID == 0) log("monster's Id is zero, hurtMe return;");
		if (m_iModelID == 0) log("monster's modelId is zero, hurtMe return;");
		if (m_iSpeed == 0) log("monster's speed is zero, hurtMe return;");
		if ( m_sprite == NULL) log("The monster has been erased, hurtMe return;");
=======
	if (m_isDead){
>>>>>>> 242d9fd9e2218bb56c21948853acb0e3a3cae294
		return;
	}

	// ��С�˺�Ϊ1
	if (iHurtValue <= getiDefense()){
		iHurtValue = 1;
	}

	int iCurHP = getiHP(); // ��ǰHP
	int iAfterHP = iCurHP - iHurtValue; // ���������HP

	onHurt(iHurtValue);
	// ��HPС����ʱ�����ǻ����onDead()����һ�Σ��������Զ�����������
	if (iAfterHP > 0) {
		setiHP(iAfterHP);
	} else {
		m_isDead = true;
		// ����
		onDead();
	}

}

bool Entity::isDead(){
	return this->m_isDead;
}

void Entity::onDead(){

}

void Entity::onBindSprite(){

}

void Entity::onHurt(int iHurtValue){

}