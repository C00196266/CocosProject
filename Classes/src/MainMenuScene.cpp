#include "MainMenuScene.h"
#include "SimpleAudioEngine.h"

USING_NS_CC;

Scene* MainMenu::createScene()
{
    auto scene = Scene::create();
    
    auto layer = MainMenu::create();

    scene->addChild(layer);

    return scene;
}

void MainMenu::activateGameScene(Ref *pSender)
{
	auto scene = GameScreen::createScene();
	Director::getInstance()->replaceScene(scene);
}

// on "init" you need to initialize your instance
bool MainMenu::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
	//auto visibleSize = Director::getInstance()->getVisibleSize();
	//Vec2 origin = Director::getInstance()->getVisibleOrigin();


	auto menuTitle =
		MenuItemImage::create("MainMenuScreen/Game_Title.png",
			"MainMenuScreen/Game_Title.png");
	auto playItem =
		MenuItemImage::create("start.png",
			"start.png",
			CC_CALLBACK_1(MainMenu::activateGameScene, this));
	auto menu = Menu::create(menuTitle, playItem, NULL);

	// Returns visible size of OpenGL window in points.
	Size visibleSize = Director::getInstance()->getVisibleSize();
	menu->alignItemsVerticallyWithPadding(visibleSize.height / 4);
	
	this->addChild(menu);

	/*
	auto playitem = MenuItemImage::create("HelloWorld.png", "CloseSelected.png", CC_CALLBACK_1(MainMenu::activateGameScene, this));
	playitem->setPosition(Vec2(origin.x + visibleSize.width/2, origin.y + playitem->getContentSize().height/2));
	// create menu, it's an autorelease object
	auto menu = Menu::create(playitem, NULL);
	menu->setPosition(Vec2::ZERO);
	this->addChild(menu, 1);


	auto label = Label::createWithSystemFont("Main Menu", "Arial", 40);
	label->setColor(Color3B(255, 255, 255));
	label->setAnchorPoint(cocos2d::Vec2(0.0, 0.0));
	this->addChild(label, 1);
	*/
	return true;
}



  
