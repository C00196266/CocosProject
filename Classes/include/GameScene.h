#pragma once

#include "cocos2d.h"
#include "GameData.h"
#include "PauseScene.h"
#include "GameOverScene.h"
#include "GameStates.h"

class GameScreen : public cocos2d::Layer
{
public:
	static cocos2d::Scene* createScene();
	virtual bool init();

	CREATE_FUNC(GameScreen);

	// Called when user pauses gameplay.
	void activatePauseScene(Ref *pSender);
	// Called at game over 
	void activateGameOverScene(Ref *pSender);

	void addBackGroundSprite(cocos2d::Size const & visibleSize, cocos2d::Point const & origin);
private:
	GameStates m_gameState;
};