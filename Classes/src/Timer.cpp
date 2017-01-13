#include "Timer.h"

GameTimer::GameTimer()
{
	seconds = 0;
	minutes = 0;
	time = 0;
	totalTime = 0;
	gameOver = false;
}

void GameTimer::incrementTimer(float deltaTime)
{
	time += deltaTime;
	totalTime += deltaTime;
	if (time > 1)
	{
		time = time - 1.0f;
		seconds++;
	}
	if (seconds == 60)
	{
		minutes++;
		seconds = 0;
	}
}

std::string GameTimer::getTimer()
{
	std::string timeString = std::to_string(minutes) + ":" + std::to_string(seconds);
	return timeString;
}

void GameTimer::resetTimer()
{
	time = 0;
	minutes = 0;
	seconds = 0;
}

int GameTimer::calulateScore(int playerScore)
{
		gameOver = true;
		// returns a value depending on how long the player takes to complete a level
		//why divide by 1000??????????????
		if (playerScore + (200/totalTime) > 0)
		{
			return (playerScore + (200 / totalTime));
		}
		else 
		{
			return 0; // doesn't subtract from the player's score/give the player a negative score
		
		}

}

int GameTimer::getSeconds()
{
	return seconds;
}

bool GameTimer::getGameOver()
{
	return gameOver;
}

void GameTimer::setGameOver(bool isGameOver)
{
	gameOver = isGameOver;
}