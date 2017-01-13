#include "HUD.h"

HUD::HUD()
{
	Size visibleSize = Director::getInstance()->getVisibleSize();

	//Score
	outputScore = CCLabelTTF::create("Score : ", "Helvetica", 23,
		CCSizeMake(245, 50), kCCTextAlignmentLeft);
	outputScore->setPosition(Vec2(175, visibleSize.height - 100));

	//Time
	outputTime = CCLabelTTF::create("Time: 0:0 ", "Helvetica", 23,
		CCSizeMake(245, 50), kCCTextAlignmentLeft);
	outputTime->setPosition(Vec2(175, visibleSize.height - 130));

	gravityPowerBar = new Rect[0, 0, 300, 50];
	gravityPowerBar->origin = Vec2(visibleSize.width-350, visibleSize.height - 100);
}

void HUD::update(int score,std::string time, float gravityPower)
{
	outputScore->setString("Score : "+ std::to_string(score));
	outputTime->setString("Time : " + time);
	gravityBar->setScaleX(gravityPower/100.0f);
}

CCLabelTTF* HUD::getLabelScore()
{
	return outputScore;
}

CCLabelTTF* HUD::getLabelTime()
{
	return outputTime;
}

Rect* HUD::getGravityBarRect()
{
	return gravityPowerBar;
}