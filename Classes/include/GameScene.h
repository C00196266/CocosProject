
#ifndef __Game_SCENE_H__
#define __Game_SCENE_H__


#include "cocos2d.h"
#include "Player.h"
#include "ScorePickup.h"
#include "CollisionDetection.h"
#include "Tiles.h"
#include "Spikes.h"
#include <vector>

using namespace std;

USING_NS_CC;
class GameScreen : public cocos2d::Layer
{
private:
	CollisionDetection m_collisionDetector;
public:

	Player *thePlayer;
    static cocos2d::Scene* createScene();
	
	ScorePickup *aScorePickup;

	vector<shared_ptr<Tiles>> m_tiles;

	vector<shared_ptr<Spikes>> m_spikes;

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
