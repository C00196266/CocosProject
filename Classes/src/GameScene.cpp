#include "GameScene.h"

USING_NS_CC;

Scene* GameScreen::createScene()
{
	// 'scene' is an autorelease object
	auto scene = Scene::create();
	auto layer = GameScreen::create();

	scene->addChild(layer);

	return scene;
}

bool GameScreen::init()
{
	if (!Layer::init())
	{
		return false;
	}

	//auto label = Label::createWithSystemFont("Hello World", "Arial", 96);
	//label->setAnchorPoint(cocos2d::Vec2(0.0f, 0.0f));
	//this->addChild(label, 1);

	//label->getPosition();

	m_gameState = GameStates::PlaceGunTower;

	auto pauseItem =
		MenuItemImage::create("GameScreen/Pause_Button.png",
			"GameScreen/Pause_Button(Click).png",
			CC_CALLBACK_1(GameScreen::activatePauseScene, this));

	Size visibleSize = Director::getInstance()->getVisibleSize();
	Point origin = Director::getInstance()->getVisibleOrigin();

	pauseItem->setPosition(Point(pauseItem->getContentSize().width -
		(pauseItem->getContentSize().width / 4) + origin.x,
		visibleSize.height - pauseItem->getContentSize().height +
		(pauseItem->getContentSize().width / 4) + origin.y));

	auto menu = Menu::create(pauseItem, NULL);
	menu->setPosition(Point::ZERO);
	this->addChild(menu);
	addBackGroundSprite(visibleSize, origin);

	return true;
}

void GameScreen::activatePauseScene(Ref *pSender)
{
	//auto scene = PauseMenu::createScene();
	auto scene = PauseScreen::createScene();
	Director::getInstance()->pushScene(TransitionFade::create(1.0, scene));
}

void GameScreen::activateGameOverScene(Ref *pSender)
{
	auto scene = GameOver::createScene();
	Director::getInstance()->replaceScene(TransitionFade::create(1.0, scene));
}

void GameScreen::addBackGroundSprite(cocos2d::Size const & visibleSize, cocos2d::Point const & origin) { 
	std::shared_ptr<GameData> ptr = GameData::sharedGameData(); 
	auto backgroundSprite = Sprite::create(ptr->m_backgroundTextureFile); 
	backgroundSprite->setPosition(Point((visibleSize.width / 2) + origin.x, (visibleSize.height / 2) + origin.y)); 
	this->addChild(backgroundSprite, -1); 
}