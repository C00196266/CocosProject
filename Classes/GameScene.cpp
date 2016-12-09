#include "GameScene.h"

#include "SimpleAudioEngine.h"
USING_NS_CC;

Scene* GameScreen::createScene()
{
	// 'scene' is an autorelease object
	auto scene = Scene::create();

	// 'layer' is an autorelease object
	auto layer = GameScreen::create();

	// add layer as a child to scene
	scene->addChild(layer);

	// return the scene
	return scene;
}


// on "init" you need to initialize your instance
bool GameScreen::init()
{
	this->scheduleUpdate();
	//////////////////////////////
	// 1. super init first
	if (!Layer::init())
	{
		return false;
	}
	//Player
	thePlayer = new Player(Vec2(75,800),Color4F::RED);
	thePlayer->setVelocity(Vec2(0, 0));
	thePlayer->image = Sprite::create("Player.png");
	thePlayer->image->setPosition(thePlayer->getPosition());
	this->addChild(thePlayer->image);

	//keyboard Input
	auto listener = EventListenerKeyboard::create();
	listener->onKeyPressed = CC_CALLBACK_2(GameScreen::onKeyPressed, this);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);
	return true;
}
void GameScreen::update(float deltaTime) 
{
	Size visibleSize = Director::getInstance()->getVisibleSize();
	//Player
	thePlayer->image->setPosition(thePlayer->getPosition());
	thePlayer->update(deltaTime);


}

void GameScreen::onKeyPressed(EventKeyboard::KeyCode keyCode, Event* event)
{
	if (keyCode == EventKeyboard::KeyCode::KEY_LEFT_ARROW)
	{
		if (thePlayer->getIsJumping() == false)
		{
			thePlayer->setVelocity(Vec2(-15, thePlayer->getVelocity().y));
			thePlayer->direction = 0;
		}
	}
	if (keyCode == EventKeyboard::KeyCode::KEY_RIGHT_ARROW)
	{
		if (thePlayer->getIsJumping() == false)
		{
			thePlayer->setVelocity(Vec2(15, thePlayer->getVelocity().y));
			thePlayer->direction = 1;
		}
	}
	if (keyCode == EventKeyboard::KeyCode::KEY_SPACE)
	{
		if (thePlayer->getIsJumping() == false)
		{
			thePlayer->setIsJumping(true);
			thePlayer->setVelocity(Vec2(thePlayer->getVelocity().x, 12.5f));
		}
	}
}

void GameScreen::menuCloseCallback(Ref* pSender)
{
	//Close the cocos2d-x game scene and quit the application
	Director::getInstance()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
	exit(0);
#endif

	/*To navigate back to native iOS screen(if present) without quitting the application  ,do not use Director::getInstance()->end() and exit(0) as given above,instead trigger a custom event created in RootViewController.mm as below*/

	//EventCustom customEndEvent("game_scene_close_event");
	//_eventDispatcher->dispatchEvent(&customEndEvent);


}


  