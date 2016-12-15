


#ifndef __Game_SCENE_H__
#define __Game_SCENE_H__


#include "cocos2d.h"
#include "Player.h"


USING_NS_CC;
class GameScreen : public cocos2d::Layer
{
public:

	Player *thePlayer;
	const float maxGravityPower = 100;

	static cocos2d::Scene* createScene();


	virtual bool init();

	// a selector callback
	void menuCloseCallback(cocos2d::Ref* pSender);

	void onKeyPressed(EventKeyboard::KeyCode keyCode, Event* event);



	void GameScreen::update(float deltaTime);
	// implement the "static create()" method manually
	CREATE_FUNC(GameScreen);
};

#endif // __Game_SCENE_H__