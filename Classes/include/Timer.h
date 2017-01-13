#pragma once
#include "cocos2d.h"
#include <string> 

USING_NS_CC;

class GameTimer
{
private:
	float time;
	float totalTime;
	int seconds;
	int minutes;
	bool gameOver;
public:
	GameTimer();

	void incrementTimer(float deltaTime);
	std::string getTimer();
	void resetTimer();
	int calulateScore(int playerScore);
	int getSeconds();
	bool getGameOver();
	void setGameOver(bool isGameOver);
};