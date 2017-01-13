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
	/*
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
	*/
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
	
	levelManager = new Level();
	levelManager->createMap();
	for (int index = 0; index < levelManager->getTiles().size(); index++)
	{
		levelManager->getTiles().at(index)->sprite = Sprite::create("Tile.png");
		levelManager->getTiles().at(index)->sprite->setPosition(levelManager->getTiles().at(index)->getPos());
		this->addChild(levelManager->getTiles().at(index)->sprite);
	}
	for (int index = 0; index < levelManager->getScorePickups().size(); index++)
	{
		levelManager->getScorePickups().at(index)->sprite = Sprite::create("pickup01.png");
		levelManager->getScorePickups().at(index)->sprite->setPosition(levelManager->getScorePickups().at(index)->getPos());
		this->addChild(levelManager->getScorePickups().at(index)->sprite);
	}
	theGoal = levelManager->getGoal();
	theGoal->sprite = Sprite::create("door.png");
	theGoal->sprite->setPosition(theGoal->getPos());
	this->addChild(theGoal->sprite);
	
	/*
	for (int i = 0; i < 2; i++) {
		m_spikes.push_back(shared_ptr<Spikes>(new Spikes(Vec2(400 + (i * 50), 50))));
		m_spikes.at(i)->sprite = Sprite::create("spike.png");
		m_spikes.at(i)->sprite->setPosition(m_spikes.at(i)->getPos());
		this->addChild(m_spikes.at(i)->sprite);
	}
	*/
	//Player
	thePlayer = new Player(Vec2(175, 800), Color4F::RED);
	thePlayer->setVelocity(Vec2(0, 0));
	thePlayer->image = Sprite::create("Player.png");
	thePlayer->image->setPosition(thePlayer->getPosition());
	this->addChild(thePlayer->image);

	theTimer = new GameTimer();

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
	
	

	//Score pickups
	for (int index = 0; index < levelManager->getScorePickups().size(); index++)
	{
		if (collisions.boundingBoxCollision(thePlayer->getPosition(), thePlayer->getSize(), levelManager->getScorePickups().at(index)->getPos(), levelManager->getScorePickups().at(index)->getSize()) == true)
		{
			score += 10;
			this->removeChild(levelManager->getScorePickups().at(index)->sprite);
			levelManager->getScorePickups().erase(levelManager->getScorePickups().begin() + index);
		}
	}
	//Goal
	if (collisions.boundingBoxCollision(thePlayer->getPosition(), thePlayer->getSize(), theGoal->getPos(), theGoal->getSize())==true&&theTimer->getGameOver()==false)
	{
		score = theTimer->calulateScore(score);
		theTimer->setGameOver(true);
		theTimer->resetTimer();
	}
	//Timer
	theTimer->incrementTimer(deltaTime);
	if (theTimer->getGameOver() == true)
	{
		if (theTimer->getSeconds() == 2)
		{
			resetScene();
		}
	}
	gameHUD->update(score,theTimer->getTimer(),thePlayer->getGravityPower());
}

void GameScreen::resetScene()
{
	thePlayer->setNextPos(Vec2(75, 800));
	thePlayer->setVelocity(Vec2(0, 0));
	thePlayer->setScore(0);
	thePlayer->setInAir(true);
	thePlayer->setAcceleration(Vec2(0, -9.8f));
	thePlayer->setGravityPower(0);
	thePlayer->setIsGravityOn(true);
	thePlayer->image->setPosition(thePlayer->getPosition());

	theTimer->setGameOver(false);
	theTimer->resetTimer();
	score = 0;

	levelManager->resetMap();
	for (int index = 0; index < levelManager->getTiles().size(); index++)
	{
		levelManager->getTiles().at(index)->sprite = Sprite::create("Tile.png");
		levelManager->getTiles().at(index)->sprite->setPosition(levelManager->getTiles().at(index)->getPos());
		this->addChild(levelManager->getTiles().at(index)->sprite);
	}
	for (int index = 0; index < levelManager->getScorePickups().size(); index++)
	{
		levelManager->getScorePickups().at(index)->sprite = Sprite::create("pickup01.png");
		levelManager->getScorePickups().at(index)->sprite->setPosition(levelManager->getScorePickups().at(index)->getPos());
		this->addChild(levelManager->getScorePickups().at(index)->sprite);
	}
}

void GameScreen::onKeyPressed(EventKeyboard::KeyCode keyCode, Event* event)
{
	if (keyCode == EventKeyboard::KeyCode::KEY_LEFT_ARROW)
	{
		if (thePlayer->getInAir() == false)
		{
			thePlayer->setVelocity(Vec2(-7.5, thePlayer->getVelocity().y));
			thePlayer->direction = 0;
		}
	}
	if (keyCode == EventKeyboard::KeyCode::KEY_RIGHT_ARROW)
	{
		if (thePlayer->getInAir() == false)
		{
			thePlayer->setVelocity(Vec2(7.5, thePlayer->getVelocity().y));
			thePlayer->direction = 1;
		}
	}
	if (keyCode == EventKeyboard::KeyCode::KEY_SPACE)
	{
		if (thePlayer->getInAir() == false)
		{
			thePlayer->setInAir(true);
			thePlayer->setVelocity(Vec2(thePlayer->getVelocity().x, 10.0f));
		}
	}
	if (keyCode == EventKeyboard::KeyCode::KEY_SHIFT)
	{
		//gravity toggle
		if (thePlayer->getGravityPower() > 0 && thePlayer->getInAir() == true)
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

void GameScreen::checkCollisions() {
	for (int i = 0; i < levelManager->getTiles().size(); i++) {
		levelManager->getTiles().at(i)->CheckCollisionWithPlayer(thePlayer);
	}

	for (int i = 0; i < levelManager->getScorePickups().size(); i++){
		thePlayer->collision(levelManager->getScorePickups().at(i)->getPos(), levelManager->getScorePickups().at(i)->getSize());
	}
}

  
