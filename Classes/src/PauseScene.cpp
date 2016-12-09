#include "PauseScene.h"

USING_NS_CC;

Scene* PauseScreen::createScene()
{
	// 'scene' is an autorelease object
	auto scene = Scene::create();
	auto layer = PauseScreen::create();

	scene->addChild(layer);

	return scene;
}

bool PauseScreen::init()
{
	if (!Layer::init())
	{
		return false;
	}

	//auto label = Label::createWithSystemFont("Hello World", "Arial", 96);
	//label->setAnchorPoint(cocos2d::Vec2(0.0f, 0.0f));
	//this->addChild(label, 1);

	//label->getPosition();

	//return true;
	auto resumeItem =
		MenuItemImage::create("PauseScreen/Resume_Button.png",
			"PauseScreen/Resume_Button(Click).png",
			CC_CALLBACK_1(PauseScreen::resume, this));
	auto retryItem =
		MenuItemImage::create("PauseScreen/Retry_Button.png",
			"PauseScreen/Retry_Button(Click).png",
			CC_CALLBACK_1(PauseScreen::retry, this));
	auto mainMenuItem =
		MenuItemImage::create("PauseScreen/Menu_Button.png",
			"PauseScreen/Menu_Button(Click).png",
			CC_CALLBACK_1(PauseScreen::activateMainMenuScene, this));
	auto menu = Menu::create(resumeItem, retryItem, mainMenuItem,
		NULL);

	Size visibleSize = Director::getInstance()->getVisibleSize();
	menu->alignItemsVerticallyWithPadding(visibleSize.height / 4);
	this->addChild(menu);

}

void PauseScreen::resume(Ref *pSender)
{
	Director::getInstance()->popScene();
}

void PauseScreen::activateMainMenuScene(Ref *pSender)
{
	auto scene = MainMenu::createScene();
	Director::getInstance()->popScene();
	Director::getInstance()->replaceScene(TransitionFade::create(1.0, scene));
}

void PauseScreen::retry(Ref *pSender)
{
	auto scene = GameScreen::createScene();
	Director::getInstance()->popScene();
	Director::getInstance()->replaceScene(TransitionFade::create(1.0, scene));
}