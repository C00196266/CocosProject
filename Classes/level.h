#pragma once

#include "cocos2d.h"
#include "Tiles.h"

USING_NS_CC;

class Level
{
public:
	int *currentLevel;
	void createMap();
	std::vector<std::shared_ptr<Tiles>> tiles;
	std::vector<std::shared_ptr<Tiles>>& Level::getTiles();
	static const int level1[16][21];
	float posX;
	float posY;
	int maxCol;
	int maxRow;
	Level();
};