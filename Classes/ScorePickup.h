
#pragma once
#include "cocos2d.h"

USING_NS_CC;

class ScorePickup
{
private:
	Vec2 m_pos;
	Vec2 m_size;

	bool m_isAlive;

	int m_scoreValue;

	Rect m_boundingBox;

public:
	ScorePickup();

	ScorePickup(Vec2 position);

	Vec2 getPos();

	void setSize(Vec2 size);
	Vec2 getSize();

	int getScoreValue();

	bool getAlive();
	void setAlive(bool aliveState);	
	Sprite *sprite;
};
