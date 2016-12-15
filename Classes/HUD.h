#pragma once
#include "cocos2d.h"

USING_NS_CC;
class HUD
{
public:
	HUD();
	void update(int score, std::string time, float gravityPower);
	CCLabelTTF* getLabelScore();
	CCLabelTTF* getLabelTime();
	Rect* getGravityBarRect();
	Sprite *gravityBar;
	Sprite *gravityBarOutline;
private:
	CCLabelTTF* outputScore;
	CCLabelTTF* outputTime;
	Rect *gravityPowerBar;
};