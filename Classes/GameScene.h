


#ifndef __Game_SCENE_H__
#define __Game_SCENE_H__


#include "cocos2d.h"
#include "CollisionDetection.h"
#include "Player.h"
#include "HUD.h"
#include "Tiles.h"
#include "Goal.h"
#include "Timer.h"
#include "level.h"
#include "ScorePickup.h"

USING_NS_CC;
class GameScreen : public cocos2d::Layer
{
public:

	Player *thePlayer;
	const float maxGravityPower = 100;
	int score;
	std::string time;
	Sprite *background;
	HUD *gameHUD;
	Tiles* aTile;
	std::shared_ptr<Goal> theGoal;
	GameTimer* theTimer;
	Level* levelManager;
	CollisionDetection collisions;

	static cocos2d::Scene* createScene();


	virtual bool init();

	// a selector callback
	void menuCloseCallback(cocos2d::Ref* pSender);
	void resetScene();
	void onKeyPressed(EventKeyboard::KeyCode keyCode, Event* event);


	void GameScreen::update(float deltaTime);
	// implement the "static create()" method manually
	CREATE_FUNC(GameScreen);
};

#endif // __Game_SCENE_H__