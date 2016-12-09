#pragma once
#include "cocos2d.h"

USING_NS_CC;

class Player
{
public:
	Player();
	Player(Vec2 m_position, Color4F colour);

	void update();
	Sprite *image;
	Vec2 getPosition();
	void setPosition(Vec2 newPosition);
	Vec2 getVelocity();
	void setVelocity(Vec2 newVelocity);
	Color4F getColour();
	void setColour(Color4F newColour);
	Vec2 getSize();
	void setSize(Vec2 newSize);
	int getScore();
	void setScore(int newScore);
	bool getIsJumping();
	void setIsJumping(bool isJumping);
private:
	
	Vec2 m_position;
	Vec2 m_velocity;
	Color4F m_colour;
	Vec2 m_size;
	int m_score;
	bool m_isJumping;
};

