#include "level.h"

Level::Level()
{
	maxRow = 16;
	maxCol = 21;
	currentLevel = (int*)level1;
	posX = 0;
	posY = 0;

}

void Level::createMap()
{
	for (int column = 0; column < maxCol; column++)
	{
		for (int row = 0; row < maxRow; row++)
		{
			if (currentLevel[maxCol*(row)+column] == 0)
			{
				//empty space
			}
			if (currentLevel[maxCol*(row)+column] == 1)
			{
				tiles.push_back(std::shared_ptr<Tiles>(new Tiles(Vec2(((column)*50)+posX, ((maxRow-row)*50)+posY-25))));
			}
			if (currentLevel[maxCol*(row)+column] == 2)
			{
				scorePickups.push_back(std::shared_ptr<ScorePickup>(new ScorePickup(Vec2(((column) * 50) + posX, ((maxRow - row) * 50) + posY-25))));
			}
			if (currentLevel[maxCol*(row)+column] == 3)
			{
				spikes.push_back(std::shared_ptr<Spikes>(new Spikes(Vec2(((column) * 50) + posX, ((maxRow - row) * 50) + posY - 25))));
			}
			if (currentLevel[maxCol*(row)+column] == 4)
			{
				theGoal = std::shared_ptr<Goal>(new Goal(Vec2(((column) * 50) + posX, ((maxRow - row) * 50) + posY - 20)));
			}
		}
	}
}

void Level::resetMap()
{
	spikes.clear();
	tiles.clear();
	scorePickups.clear();
	createMap();
}

const int Level::level1[16][21] =
{
	{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
	{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 1},
	{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 2, 0, 4, 0, 1},
	{1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1, 1},
	{1, 0, 0, 0, 0, 0, 0, 2, 0, 1, 1, 1, 3, 3, 3, 3, 1, 1, 1, 1, 1},
	{1, 0, 0, 0, 0, 2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
	{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
};

std::vector<std::shared_ptr<Tiles>>& Level::getTiles()
{
	return tiles;
}

std::shared_ptr<Goal> Level::getGoal()
{
	return theGoal;
}

std::vector<std::shared_ptr<ScorePickup>>& Level::getScorePickups()
{
	return scorePickups;
}

std::vector<std::shared_ptr<Spikes>>& Level::getSpikes()
{
	return spikes;
}