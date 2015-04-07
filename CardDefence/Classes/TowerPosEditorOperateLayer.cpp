#include "TowerPosEditorOperateLayer.h"
#include "TowerPosEditorLayer.h"
#include "PosBase.h"
#include "SceneManager.h"
#include "EnumPosType.h"

TowerPosEditorOperateLayer::TowerPosEditorOperateLayer(){

}

TowerPosEditorOperateLayer::~TowerPosEditorOperateLayer(){

}

TowerPosEditorOperateLayer* TowerPosEditorOperateLayer::create(TowerPosEditorLayer* layer){
	TowerPosEditorOperateLayer* oprLayer = new TowerPosEditorOperateLayer();
	if (oprLayer && oprLayer->init(layer)){
		oprLayer->autorelease();
	}else {
		CC_SAFE_DELETE(oprLayer);
	}
	return oprLayer;
}

bool TowerPosEditorOperateLayer::init(TowerPosEditorLayer* layer){
	if (!Layer::init()) return false;

	this->m_editorLayer = layer;

	// 加载UI
	auto UI = cocostudio::GUIReader::getInstance()->widgetFromJsonFile("EditorOperate/EditorOperate_1.ExportJson");
	this->addChild(UI);
	
	// 主要
	UI->setTouchEnabled(false);

	// 获取控件对象
	auto outputBtn = (Button*)Helper::seekWidgetByName(UI, "outputBtn");
	auto changeModeBtn = (Button*)Helper::seekWidgetByName(UI, "changeModeBtn");
	auto nextLevelBtn = (Button*)Helper::seekWidgetByName(UI, "nextLevelBtn");
	auto preLevelBtn = (Button*)Helper::seekWidgetByName(UI, "preLevelBtn");
	auto backBtn = (Button*)Helper::seekWidgetByName(UI, "backBtn");


	// 添加单击监听
	outputBtn->addTouchEventListener(this, toucheventselector(TowerPosEditorOperateLayer::outputBtnOnClick));
	changeModeBtn->addTouchEventListener(this, toucheventselector(TowerPosEditorOperateLayer::changeModeBtnOnClick));
	nextLevelBtn->addTouchEventListener(this, toucheventselector(TowerPosEditorOperateLayer::nextLevelBtnOnClick));
	preLevelBtn->addTouchEventListener(this, toucheventselector(TowerPosEditorOperateLayer::preLevelBtnOnClick));
	backBtn->addTouchEventListener(this, toucheventselector(TowerPosEditorOperateLayer::backBtnOnClick));


	m_labLog = LabelTTF::create();
	m_labLog->setString("Writing Succeed");
	m_labLog->setFontSize(24);
	m_labLog->setFontName("Arial");
	m_labLog->setColor(Color3B::GREEN);
	m_labLog->setVisible(false);
	m_labLog->setPosition(this->getContentSize()/2);
	this->addChild(m_labLog);
	return true;
}

void TowerPosEditorOperateLayer::backBtnOnClick(Ref*, TouchEventType type){
	if (type == TouchEventType::TOUCH_EVENT_ENDED) {
		SceneManager::getInstance()->changeScene(SceneManager::en_TollgateStartScene);
	}
}

void TowerPosEditorOperateLayer::outputBtnOnClick(Ref*, TouchEventType type){
	if (type == TouchEventType::TOUCH_EVENT_ENDED) {
		if (m_editorLayer->outputPosToPlistFile()){
			m_labLog->setString("Writing Succeed!");
			//UserDefault::getInstance()->setStringForKey("OutPut","Writing Succeed!");
		} else {
			m_labLog->setString("Writing failed!");
			m_labLog->setColor(Color3B::RED);
			//UserDefault::getInstance()->setStringForKey("OutPut","Writing failed!");
		}
		m_labLog->setVisible(true);
		this->scheduleOnce(schedule_selector(TowerPosEditorOperateLayer::scheduleOnceLab), 3);
		//CCLOG("outputBtnOnClick");
	}
}

void TowerPosEditorOperateLayer::changeModeBtnOnClick(Ref*, TouchEventType type){
	if (type == TouchEventType::TOUCH_EVENT_ENDED){
		//m_labLog->setString(UserDefault::getInstance()->getStringForKey("OutPut"));
		switch(m_editorLayer->changeMode()){
		case EnumPosType::enMonsterPos:
			m_labLog->setString("change to MonsterPos!");
			break;
		case EnumPosType::enTowerPos:
			m_labLog->setString("change to TowerPos!");
			break;
		}
		//CCLOG("changeModeBtnOnClick");
		m_labLog->setVisible(true);
		this->scheduleOnce(schedule_selector(TowerPosEditorOperateLayer::scheduleOnceLab), 3);
	}
}
void TowerPosEditorOperateLayer::scheduleOnceLab(float dt){
	m_labLog->setVisible(false);
	m_labLog->setColor(Color3B::GREEN);
}

void TowerPosEditorOperateLayer::nextLevelBtnOnClick(Ref*, TouchEventType type){
	if (type == TouchEventType::TOUCH_EVENT_ENDED) {
		m_editorLayer->nextLvl();
		//CCLOG("nextLevelBtnOnClick");
	}
}

void TowerPosEditorOperateLayer::preLevelBtnOnClick(Ref*, TouchEventType type){
	if (type == TouchEventType::TOUCH_EVENT_ENDED) {
		m_editorLayer->preLvl();
		//CCLOG("preLevelBtnOnClick");
	}
}

void TowerPosEditorOperateLayer::draw(Renderer *renderer, const kmMat4 &transform, bool transformUpdated){
	_customCommand.init(_globalZOrder);
	_customCommand.func = CC_CALLBACK_0(TowerPosEditorOperateLayer::onDraw, this, transform, transformUpdated);
	renderer->addCommand(&_customCommand);
}

void TowerPosEditorOperateLayer::onDraw(const kmMat4 &transform, bool transformUpdated){
	kmGLPushMatrix();// 把当前状态做一个副本放入堆栈之中。
	kmGLLoadMatrix(&transform);
	Vector<PosBase*> m_monsterPosList = m_editorLayer->getMonsterPosList();
	PosBase* prePos = NULL;
	for (auto posBase : m_monsterPosList){
		if (prePos != NULL){
			DrawPrimitives::drawLine(prePos->getPos(), posBase->getPos());
		}
		prePos = posBase;
	}
	// 绘制结束 把刚刚保存的那个位置和角度恢复。
	kmGLPopMatrix();
}