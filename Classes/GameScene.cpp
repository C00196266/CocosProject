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
	this->scheduleUpdate();
	if (!Layer::init())
	{
		return false;
	}

	//background = Sprite::create("Background.png");
	//background->setAnchorPoint(Vec2(0, 1));
	//background->setPosition(0, Director::getInstance()->getVisibleSize().height+100);
	//this->addChild(background);
	auto background = cocos2d::LayerColor::create(Color4B(160, 193, 255, 255));
	this->addChild(background);

	score = 0;
	time = "0:0";
	gameHUD = new HUD();
	this->addChild(gameHUD->getLabelScore());
	this->addChild(gameHUD->getLabelTime());

	gameHUD->gravityBar = Sprite::create("GravityBar.png");
	gameHUD->gravityBar->setAnchorPoint(Vec2(0,1));
	gameHUD->gravityBar->setPosition(gameHUD->getGravityBarRect()->origin);
	this->addChild(gameHUD->gravityBar);

	gameHUD->gravityBarOutline = Sprite::create("GravityBarOutline.png");
	gameHUD->gravityBarOutline->setAnchorPoint(Vec2(0, 1));
	gameHUD->gravityBarOutline->setPosition(gameHUD->getGravityBarRect()->origin);
	this->addChild(gameHUD->gravityBarOutline);



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
	gameHUD->update(score,time,thePlayer->getGravityPower());
}
void GameScreen::onKeyPressed(EventKeyboard::KeyCode keyCode, Event* event)
{
	if (keyCode == EventKeyboard::KeyCode::KEY_LEFT_ARROW)
	{
		if (thePlayer->getIsJumping() == false)
		{
			thePlayer->setVelocity(Vec2(-7.5, thePlayer->getVelocity().y));
			thePlayer->direction = 0;
		}
	}
	if (keyCode == EventKeyboard::KeyCode::KEY_RIGHT_ARROW)
	{
		if (thePlayer->getIsJumping() == false)
		{
			thePlayer->setVelocity(Vec2(7.5, thePlayer->getVelocity().y));
			thePlayer->direction = 1;
		}
	}
	if (keyCode == EventKeyboard::KeyCode::KEY_SPACE)
	{
		if (thePlayer->getIsJumping() == false)
		{
			thePlayer->setIsJumping(true);
			thePlayer->setVelocity(Vec2(thePlayer->getVelocity().x, 10.0f));
		}
	}
	if (keyCode == EventKeyboard::KeyCode::KEY_SHIFT)
	{
		//gravity toggle
		if (thePlayer->getGravityPower() > 0 && thePlayer->getIsJumping() == true)
		{
			if (thePlayer->getIsGravityOn() == false)
			{
				thePlayer->setAcceleration(Vec2(0, -9.8));
				thePlayer->setIsGravityOn(true);
			}
			else
			{
				thePlayer->setAcceleration(Vec2(0, 0));
				thePlayer->setIsGravityOn(false);
			}
		}
	}
}

void GameScreen::menuCloseCallback(Ref* pSender)
{
	//Close the cocos2d-x game scene and quit the application
	Director::getInstance()->end();
}
