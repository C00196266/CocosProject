

#pragma once
#include "Player.h"
#define COCOS2D_DEBUG 1

Player::Player()
{
	m_position = Vec2(50, 50);
	m_colour = Color4F::GREEN;
	m_size = Vec2(50, 50);
	m_score = 0;
	m_isJumping = true;
	m_acceleration = Vec2(0,-9.8f);
	m_gravityPower = 0;
	m_isGravityOn = true;
}

Player::Player(Vec2 position, Color4F colour)
{
	m_position = position;
	m_colour = colour;
	m_size = Vec2(50, 50);
	m_score = 0;
	m_isJumping = true;
	m_acceleration = Vec2(0, -9.8f);
	m_gravityPower = 0;
	m_isGravityOn = true;
}

void Player::update(float deltaTime)
{
	if (m_gravityPower + m_gravityPowerRegen < 100)
	{
		m_gravityPower += m_gravityPowerRegen;
	}
	else
	{
		m_gravityPower = 100;
	}

	if (m_isGravityOn == false & m_gravityPower > 0)//Gravity Power Reduction
	{
		m_gravityPower -= 1.0;
		if (m_gravityPower < 0)
		{
			m_gravityPower = 0;
			m_acceleration.y = -9.8;
			m_isGravityOn = true;
		}
	}
	if (m_isJumping == false)
	{
		if (direction == 0)//Left Direction
		{
			if (m_velocity.x >= 0)
			{
				m_velocity.x = 0;
			}
			else
			{
				m_velocity.x += 0.1;
			}
		}
		if (direction == 1)//Right Direction
		{
			if (m_velocity.x <= 0)
			{
				m_velocity.x = 0;
			}
			else
			{
				m_velocity.x -= 0.1;
			}
		}
	}
	if (m_velocity.x == 0 && m_velocity.y == 0)
	{
		m_acceleration.y = 0;
	}
	m_position.x += m_velocity.x;

	//m_velocity.y += m_acceleration.y*deltaTime;

	if (m_position.y + m_velocity.y > (m_size.x/2))//Gravity
	{
		m_position.y += m_velocity.y;
	}
	else
	{
		m_isJumping = false;
	}

}





//Position
Vec2 Player::getPosition()
{
	return m_position;
}
void Player::setPosition(Vec2 newPos)
{
	m_position = newPos;
}

//Velocity
Vec2 Player::getVelocity()
{
	return m_velocity;
}
void Player::setVelocity(Vec2 newVelocity)
{
	m_velocity = newVelocity;
}

//Colour
Color4F Player::getColour()
{
	return m_colour;
}
void Player::setColour(Color4F newColour)
{
	m_colour = newColour;
}

//Size
Vec2 Player::getSize()
{
	return m_size;
}
void Player::setSize(Vec2 newSize)
{
	m_size = newSize;
}

//Score
int Player::getScore()
{
	return m_score;
}
void Player::setScore(int newScore)
{
	m_score = newScore;
}

//Jumping
bool Player::getIsJumping()
{
	return m_isJumping;
}
void Player::setIsJumping(bool isJumping)
{
	m_isJumping = isJumping;
}

//Gravity Power
float Player::getGravityPower()
{
	return m_gravityPower;
}
void Player::setGravityPower(float newGravityPower)
{
	m_gravityPower = newGravityPower;
}

//Jumping
bool Player::getIsGravityOn()
{
	return m_isGravityOn;
}
void Player::setIsGravityOn(bool isGravityOn)
{
	m_isGravityOn = isGravityOn;
}

Vec2 Player::getAcceleration()
{
	return m_acceleration;
}
void Player::setAcceleration(Vec2 newAcceleration)
{
	m_acceleration = newAcceleration;
}

bool Player::collisionTop(Rect other)
{
	bool collides = false;
	if (m_position.y + m_velocity.y < other.getMaxY() && !(m_position.y > other.getMaxY()))
	{
		if (m_position.x + m_size.x > other.getMinX() && m_position.x < other.getMaxX())
		{
			collides = true;
			//m_position.y = other.getMaxY() + m_size.y;
			//m_velocity.x = 0;
			m_velocity.y = 0;
			m_isJumping = false;
			CCLOG("%s", "It worked");
		}
	}

	return collides;
}

bool Player::collision(Vec2 otherPosition, Vec2 otherSize)
{
	bool collides = false;

	if ((m_position.x < otherPosition.x + otherSize.x) && (m_position.x + m_size.x > otherPosition.x)
		&& (m_position.y + m_size.y > otherPosition.y) && (m_position.y < otherPosition.y + otherSize.y)) {
		collides = true;
	}

	return collides;
}