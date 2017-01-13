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
		m_tiles.push_back(shared_ptr<Tiles>(new Tiles(Vec2(25 + (i * 50), 25))));
		m_tiles.at(i)->sprite = Sprite::create("metalTile.png");
		m_tiles.at(i)->sprite->setPosition(m_tiles.at(i)->getPos());
		this->addChild(m_tiles.at(i)->sprite);
	}

	m_tiles.push_back(shared_ptr<Tiles>(new Tiles(Vec2(25, 75))));
	m_tiles.at(m_tiles.size() - 1)->sprite = Sprite::create("metalTile.png");
	m_tiles.at(m_tiles.size() - 1)->sprite->setPosition(m_tiles.at(m_tiles.size() - 1)->getPos());
	this->addChild(m_tiles.at(m_tiles.size() - 1)->sprite);

	m_tiles.push_back(shared_ptr<Tiles>(new Tiles(Vec2(25, 75))));
	m_tiles.at(m_tiles.size() - 1)->sprite = Sprite::create("metalTile.png");
	m_tiles.at(m_tiles.size() - 1)->sprite->setPosition(m_tiles.at(m_tiles.size() - 1)->getPos());
	this->addChild(m_tiles.at(m_tiles.size() - 1)->sprite);

	m_tiles.push_back(shared_ptr<Tiles>(new Tiles(Vec2(25, 125))));
	m_tiles.at(m_tiles.size() - 1)->sprite = Sprite::create("metalTile.png");
	m_tiles.at(m_tiles.size() - 1)->sprite->setPosition(m_tiles.at(m_tiles.size() - 1)->getPos());
	this->addChild(m_tiles.at(m_tiles.size() - 1)->sprite);

	m_tiles.push_back(shared_ptr<Tiles>(new Tiles(Vec2(25, 175))));
	m_tiles.at(m_tiles.size() - 1)->sprite = Sprite::create("metalTile.png");
	m_tiles.at(m_tiles.size() - 1)->sprite->setPosition(m_tiles.at(m_tiles.size() - 1)->getPos());
	this->addChild(m_tiles.at(m_tiles.size() - 1)->sprite);

	m_tiles.push_back(shared_ptr<Tiles>(new Tiles(Vec2(25, 225))));
	m_tiles.at(m_tiles.size() - 1)->sprite = Sprite::create("metalTile.png");
	m_tiles.at(m_tiles.size() - 1)->sprite->setPosition(m_tiles.at(m_tiles.size() - 1)->getPos());
	this->addChild(m_tiles.at(m_tiles.size() - 1)->sprite);


	m_tiles.push_back(shared_ptr<Tiles>(new Tiles(Vec2(25, 275))));
	m_tiles.at(m_tiles.size() - 1)->sprite = Sprite::create("metalTile.png");
	m_tiles.at(m_tiles.size() - 1)->sprite->setPosition(m_tiles.at(m_tiles.size() - 1)->getPos());
	this->addChild(m_tiles.at(m_tiles.size() - 1)->sprite);

	m_tiles.push_back(shared_ptr<Tiles>(new Tiles(Vec2(25, 325))));
	m_tiles.at(m_tiles.size() - 1)->sprite = Sprite::create("metalTile.png");
	m_tiles.at(m_tiles.size() - 1)->sprite->setPosition(m_tiles.at(m_tiles.size() - 1)->getPos());
	this->addChild(m_tiles.at(m_tiles.size() - 1)->sprite);

	m_tiles.push_back(shared_ptr<Tiles>(new Tiles(Vec2(25, 375))));
	m_tiles.at(m_tiles.size() - 1)->sprite = Sprite::create("metalTile.png");
	m_tiles.at(m_tiles.size() - 1)->sprite->setPosition(m_tiles.at(m_tiles.size() - 1)->getPos());
	this->addChild(m_tiles.at(m_tiles.size() - 1)->sprite);

	m_tiles.push_back(shared_ptr<Tiles>(new Tiles(Vec2(25, 425))));
	m_tiles.at(m_tiles.size() - 1)->sprite = Sprite::create("metalTile.png");
	m_tiles.at(m_tiles.size() - 1)->sprite->setPosition(m_tiles.at(m_tiles.size() - 1)->getPos());
	this->addChild(m_tiles.at(m_tiles.size() - 1)->sprite);

	m_tiles.push_back(shared_ptr<Tiles>(new Tiles(Vec2(25, 475))));
	m_tiles.at(m_tiles.size() - 1)->sprite = Sprite::create("metalTile.png");
	m_tiles.at(m_tiles.size() - 1)->sprite->setPosition(m_tiles.at(m_tiles.size() - 1)->getPos());
	this->addChild(m_tiles.at(m_tiles.size() - 1)->sprite);

	m_tiles.push_back(shared_ptr<Tiles>(new Tiles(Vec2(25, 525))));
	m_tiles.at(m_tiles.size() - 1)->sprite = Sprite::create("metalTile.png");
	m_tiles.at(m_tiles.size() - 1)->sprite->setPosition(m_tiles.at(m_tiles.size() - 1)->getPos());
	this->addChild(m_tiles.at(m_tiles.size() - 1)->sprite);

	m_tiles.push_back(shared_ptr<Tiles>(new Tiles(Vec2(25, 575))));
	m_tiles.at(m_tiles.size() - 1)->sprite = Sprite::create("metalTile.png");
	m_tiles.at(m_tiles.size() - 1)->sprite->setPosition(m_tiles.at(m_tiles.size() - 1)->getPos());
	this->addChild(m_tiles.at(m_tiles.size() - 1)->sprite);

	m_tiles.push_back(shared_ptr<Tiles>(new Tiles(Vec2(75, 75))));
	m_tiles.at(m_tiles.size() - 1)->sprite = Sprite::create("metalTile.png");
	m_tiles.at(m_tiles.size() - 1)->sprite->setPosition(m_tiles.at(m_tiles.size() - 1)->getPos());
	this->addChild(m_tiles.at(m_tiles.size() - 1)->sprite);

	for (int i = 0; i < 2; i++) {
		m_spikes.push_back(shared_ptr<Spikes>(new Spikes(Vec2(400 + (i * 50), 50))));
		m_spikes.at(i)->sprite = Sprite::create("spike.png");
		m_spikes.at(i)->sprite->setPosition(m_spikes.at(i)->getPos());
		this->addChild(m_spikes.at(i)->sprite);
	}

	aScorePickup = new ScorePickup(Vec2(700, 350));
	aScorePickup->sprite = Sprite::create("pickup01.png");
	aScorePickup->sprite->setPosition(aScorePickup->getPos());
	this->addChild(aScorePickup->sprite);

	//Player
	thePlayer = new Player(Vec2(175, 80), Color4F::RED);
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
	thePlayer->update(deltaTime);
	checkCollisions();
	thePlayer->image->setPosition(thePlayer->getPosition());
}

void GameScreen::onKeyPressed(EventKeyboard::KeyCode keyCode, Event* event)
{
	if (keyCode == EventKeyboard::KeyCode::KEY_LEFT_ARROW)
	{
		if (thePlayer->getInAir() == false)
		{
			thePlayer->setVelocity(Vec2(-10, thePlayer->getVelocity().y));
			thePlayer->direction = 0;
		}
	}
	if (keyCode == EventKeyboard::KeyCode::KEY_RIGHT_ARROW)
	{
		if (thePlayer->getInAir() == false)
		{
			thePlayer->setVelocity(Vec2(10, thePlayer->getVelocity().y));
			thePlayer->direction = 1;
		}
	}
	if (keyCode == EventKeyboard::KeyCode::KEY_SPACE)
	{
		if (thePlayer->getInAir() == false)
		{
			thePlayer->setInAir(true);
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
	for (int i = 0; i < m_tiles.size(); i++) {
		m_tiles.at(i)->CheckCollisionWithPlayer(thePlayer);
	}

	for (int i = 0; i < m_spikes.size(); i++){
		m_spikes.at(i)->CheckCollisionWithPlayer(thePlayer);
	}
}

  
