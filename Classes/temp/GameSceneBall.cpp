#include "GameScene.h"
#include "SimpleAudioEngine.h"
#include "PauseScene.h"
#include "GameOverScene.h"
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
void GameScreen::activatePauseScene(Ref *pSender)
{
	auto scene = PauseScreen::createScene();
	Director::getInstance()->pushScene(scene);
}

void GameScreen::activateGameOverScene(Ref *pSender)
{
	auto scene = GameOver::createScene();
	Director::getInstance()->replaceScene(scene);
}
// on "init" you need to initialize your instance
bool GameScreen::init()
{
	this->scheduleUpdate();
	velocity = Point(-0,0)*physicsScale;
	gravity =  Point(0.0f, -4.95f)*physicsScale;

	bulletSprite = Sprite::create("GameScreen/bullet.png");
	bulletSprite->setPosition(300, 300);
	bulletSprite->setAnchorPoint(Vec2(0.5, 0));
	this->addChild(bulletSprite);

	velocity = Point(-0, 0);
	isFired = false;
	direction = DOWN;
	
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }

    /////////////////////////////
    // 2. add a menu item with "X" image, which is clicked to quit the program
    //    you may modify it.

    // add a "close" icon to exit the progress. it's an autorelease object

	auto pauseItem =
		MenuItemImage::create("GameScreen/Pause_Button.png",
			"GameScreen/Pause_Button(Click).png",
			CC_CALLBACK_1(GameScreen::activatePauseScene, this));

	

	 mySprite = Sprite::create("GameScreen/football.png");
	 mySprite->setPosition(300, 300);
	mySprite->setAnchorPoint( Vec2(0.5, 0));
	this->addChild(mySprite);
	
	Size visibleSize = Director::getInstance()->getVisibleSize();
	Point origin = Director::getInstance()->getVisibleOrigin();

	pauseItem->setPosition(Point(pauseItem->getContentSize().width -
		(pauseItem->getContentSize().width / 4) + origin.x,
		visibleSize.height - pauseItem->getContentSize().height +
		(pauseItem->getContentSize().width / 4) + origin.y));

	auto menu = Menu::create(pauseItem, NULL);
	menu->setPosition(Point::ZERO);
	this->addChild(menu);

	auto eventListener = EventListenerKeyboard::create();

	eventListener->onKeyPressed = [this](EventKeyboard::KeyCode keyCode, Event* event) {

		Vec2 loc = event->getCurrentTarget()->getPosition();
		switch (keyCode) {
		case EventKeyboard::KeyCode::KEY_LEFT_ARROW:
		case EventKeyboard::KeyCode::KEY_A:
			velocity.x -= 150;
			direction = LEFT;
			break;
		case EventKeyboard::KeyCode::KEY_RIGHT_ARROW:
		case EventKeyboard::KeyCode::KEY_D:
			velocity.x += 150;
			direction = RIGHT;
			break;
		case EventKeyboard::KeyCode::KEY_SPACE:
			velocity.y += 500;
			if (velocity.y > 0) {
				direction = UP;
			}
			else {
				direction = DOWN;
			}
			break;
		case EventKeyboard::KeyCode::KEY_S:
			if (direction == UP) {
				velocity.y -= 5;
			}
			else if (direction == LEFT) {
				velocity.x += 5;
			}
			else if (direction == RIGHT) {
				velocity.x -= 5;
			}
			else {
				velocity.y += 5;
			}
			isFired = true;
			break;
		}
	};

	this->_eventDispatcher->addEventListenerWithSceneGraphPriority(eventListener, mySprite);
    
    return true;
}
void GameScreen::update(float deltaTime) {

	auto position = mySprite->getPosition();
	auto bulletPosition = bulletSprite->getPosition();
	
	position = position + velocity* deltaTime + 0.5f*gravity*pow(deltaTime, 2);

	if (position.y < -48) {
		velocity.y = 0;
		position.y = 480;
	}
	if (position.y > 480) {
		position.y = -48;
	}
	if (position.x < -64) {
		position.x = 640;
	}
	if (position.x > 640) {
		position.x = -64;
	}

	velocity = velocity + gravity*deltaTime;


	if (isFired == true) {
		if (direction == UP) {
			bulletVelocity.y += 5;
		}
		else if (direction == LEFT) {
			bulletVelocity.x -= 5;
		}
		else if (direction == RIGHT) {
			bulletVelocity.x += 5;
		}
		else {
  			bulletVelocity.y -= 5;
		}

		if (bulletPosition.y < -48 || bulletPosition.y > 480 || bulletPosition.x < -100 || bulletPosition.x > 640) {
			isFired = false;
			bulletVelocity.x = 0;
			bulletVelocity.y = 0;
		}
		bulletPosition += bulletVelocity;
	}
	else {
		bulletPosition = position;
	}
	
	mySprite->setPosition(position);
	bulletSprite->setPosition(bulletPosition);
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
