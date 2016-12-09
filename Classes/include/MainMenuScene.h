#pragma once

#include "cocos2d.h"
#include "GameScene.h"

class MainMenu : public cocos2d::Layer
{
public:
	static cocos2d::Scene* createScene();
	virtual bool init();

	CREATE_FUNC(MainMenu);
	
	void activateGameScene(Ref * pSender);
};

