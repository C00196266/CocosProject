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

	for (int i = 0; i < 10; i++) {
		//m_tiles.push_back(new shared_ptr<Tiles>(i * 50, 0));
	}

	aScorePickup = new ScorePickup(Vec2(70, 35));
	aScorePickup->sprite = Sprite::create("pickup01.png");
	aScorePickup->sprite->setPosition(aScorePickup->getPos());
	this->addChild(aScorePickup->sprite);

	//Player
	thePlayer = new Player(Vec2(75, 800), Color4F::RED);
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
	checkCollisions();
	thePlayer->update(deltaTime);
	thePlayer->image->setPosition(thePlayer->getPosition());
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
}

void GameScreen::checkCollisions() {
	if (m_collisionDetector.boundingBoxCollision(thePlayer->image->getBoundingBox(), aScorePickup->sprite->getBoundingBox()) == true) {
		thePlayer->setPosition(thePlayer->lastPosition);
		thePlayer->setVelocity(Vec2(0,0));
		thePlayer->setGravity(0);
	}
	else {
		thePlayer->setGravity(-9.8f);
	}
}

  
