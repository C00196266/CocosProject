#include "GameScene.h"
#include "AppDelegate.h"


USING_NS_CC;

AppDelegate::AppDelegate()
{
}

AppDelegate::~AppDelegate()
{
}


bool AppDelegate::applicationDidFinishLaunching() {
	// initialize director
	auto director = Director::getInstance();
	auto glview = director->getOpenGLView();
	if (!glview)
	{
		glview = GLViewImpl::create("Graviball");
		glview->setFrameSize(960, 680);
		director->setOpenGLView(glview);
	}
	// create a scene. it's an autorelease object
	auto scene = GameScreen::createScene();

	// run
	director->runWithScene(scene);

	return true;
}

// This function will be called when the app is inactive. Note, when receiving a phone call it is invoked.
void AppDelegate::applicationDidEnterBackground()
{
}

// this function will be called when the app is active again
void AppDelegate::applicationWillEnterForeground()
{
}