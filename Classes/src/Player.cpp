

#pragma once
#include "Player.h"


Player::Player()
{
	m_position = Vec2(50, 50);
	m_colour = Color4F::GREEN;
	m_size = Vec2(50, 50);
	m_score = 0;
	m_isJumping = false;
	m_acceleration = Vec2(0, -9.8f);
}

Player::Player(Vec2 position, Color4F colour)
{
	m_position = position;
	m_colour = colour;
	m_size = Vec2(50, 50);
	m_score = 0;
	m_isJumping = false;
	m_acceleration = Vec2(0, -9.8f);
}

void Player::update(float deltaTime)
{
	lastPosition = m_position;
	m_velocity.y += m_acceleration.y*deltaTime;
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
				m_velocity.x += 0.2;
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
				m_velocity.x -= 0.2;
			}
		}
	}
	m_position.x += m_velocity.x;

	if (m_position.y + m_velocity.y > (m_size.x / 2))//Gravity
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

void Player::setGravity(float gravity) {
	m_acceleration.y = gravity;
}

float Player::getGravity() {
	return m_acceleration.y;
}