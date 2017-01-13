


#ifndef __Game_SCENE_H__
#define __Game_SCENE_H__


#include "cocos2d.h"
#include "Player.h"
#include "ScorePickup.h"
#include "CollisionDetection.h"
#include "Tiles.h"
#include "Spikes.h"
#include <vector>
#include "HUD.h"

using namespace std;

USING_NS_CC;
class GameScreen : public cocos2d::Layer
{
private:
	CollisionDetection m_collisionDetector;
public:
	Player *thePlayer;
	const float maxGravityPower = 100;
	int score;
	std::string time;
	Sprite *background;
	HUD *gameHUD;

	static cocos2d::Scene* createScene();


	virtual bool init();

	// a selector callback
	void menuCloseCallback(cocos2d::Ref* pSender);

	void onKeyPressed(EventKeyboard::KeyCode keyCode, Event* event);

	void checkCollisions();

	void GameScreen::update(float deltaTime);
	// implement the "static create()" method manually
	CREATE_FUNC(GameScreen);
};

#endif // __Game_SCENE_H__