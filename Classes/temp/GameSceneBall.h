#ifndef __Game_SCENE_H__
#define __Game_SCENE_H__

#include "cocos2d.h"
#include "Bullet.h"

USING_NS_CC;
class GameScreen : public cocos2d::Layer
{
public:
	std::vector<Bullet> bullets;
	// the physicsScale is used because the units for gravity are meters, so 
	// a 64 pixel wide ball will act like a 64 meter wide ball.
	// to scale it down to normal ball size we use the below scale
	double physicsScale = 64 * 10;
	
	Sprite *bulletSprite;
	Sprite *mySprite;
	Point velocity;
	Point gravity;
    static cocos2d::Scene* createScene();

	Point bulletVelocity;
	bool isFired;
	int direction;
	int const UP = 0;
	int const LEFT = 1;
	int const DOWN = 2;
	int const RIGHT = 3;

    virtual bool init();
    
    // a selector callback
    void menuCloseCallback(cocos2d::Ref* pSender);
	// Called when user pauses gameplay.
	void activatePauseScene(Ref *pSender);
	// Called at game over 
	void activateGameOverScene(Ref *pSender);

	void GameScreen::update(float deltaTime);
    // implement the "static create()" method manually
    CREATE_FUNC(GameScreen);
};

#endif // __Game_SCENE_H__
