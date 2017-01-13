#pragma once

#include "cocos2d.h"
#include "Goal.h"
#include "Tiles.h"
#include "ScorePickup.h"

USING_NS_CC;

class Level
{
public:
	int *currentLevel;
	std::shared_ptr<Goal> theGoal;
	std::shared_ptr<Goal> getGoal();
	void createMap();
	void resetMap();
	std::vector<std::shared_ptr<Tiles>> tiles;
	std::vector<std::shared_ptr<Tiles>>& Level::getTiles();
	std::vector<std::shared_ptr<ScorePickup>> scorePickups;
	std::vector<std::shared_ptr<ScorePickup>>& Level::getScorePickups();
	static const int level1[16][21];
	float posX;
	float posY;
	int maxCol;
	int maxRow;
	Level();
};