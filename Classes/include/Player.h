#pragma once
#include "cocos2d.h"

USING_NS_CC;

class Player
{
public:
	Player();
	Player(Vec2 m_position, Color4F colour);

	int direction;
	void update(float deltaTime);

	Sprite *image;

	Vec2 getPosition();
	void setPosition(Vec2 newPosition);

	Vec2 getVelocity();
	void setVelocity(Vec2 newVelocity);
	void setXVelocity(float xVel);
	void setYVelocity(float yVel);

	Color4F getColour();
	void setColour(Color4F newColour);

	Vec2 getSize();
	void setSize(Vec2 newSize);

	int getScore();
	void setScore(int newScore);

	//bool getIsJumping();
	//void setIsJumping(bool isJumping);

	bool getInAir();
	void setInAir(bool inAir);

	Vec2 lastPosition;
	float getGravity();
	void setGravity(float value);

	Rect getBoundingBox();
	void setBoundingBox(Rect newBox);

	float getX();
	void setX(float x);
	float getY();
	void setY(float y);

	float right();
	//float bottom();
	float top();
	//float left();

	Vec2 getNextPos();
	void setNextPos(Vec2 pos);

	float nextX();
	void setNextX(float nextX);
	float nextRight();
	void setNextY(float nextY);
	float nextY();
	float nextTop();
	
	float getGravityPower();
	void setGravityPower(float newGravityPower);
	bool getIsGravityOn();
	void setIsGravityOn(bool isGravityOn);

	bool collision(Vec2 otherPosition, Vec2 otherSize);

	Vec2 getAcceleration();
	void setAcceleration(Vec2 newAcceleration);

private:
	Vec2 m_acceleration;
	Vec2 m_position;
	Vec2 m_nextPosition;
	Vec2 m_velocity;
	Color4F m_colour;
	Vec2 m_size;
	int m_score;
	bool m_inAir;
	float m_gravityPower;
	bool m_isGravityOn;
	const float m_gravityPowerRegen = 0.2;
	Rect m_boundingBox;
};
