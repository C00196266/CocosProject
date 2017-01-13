

#pragma once
#include "Player.h"


Player::Player()
{
	m_position = Vec2(50, 50);
	m_nextPosition = m_position;
	m_colour = Color4F::GREEN;
	m_size = Vec2(45, 45);
	m_score = 0;
	m_inAir = true;
	m_acceleration = Vec2(0, -9.8f);
	m_boundingBox = Rect(m_position.x, m_position.y, m_size.x, m_size.y);
	m_gravityPower = 0;
	m_isGravityOn = true;
	m_collision = false;
	m_isAlive = true;
}

Player::Player(Vec2 position, Color4F colour)
{
	m_position = position;
	m_nextPosition = m_position;
	m_colour = colour;
	m_size = Vec2(45, 45);
	m_score = 0;
	m_inAir = true;
	m_acceleration = Vec2(0, -9.8f);
	m_boundingBox = Rect(m_position.x, m_position.y, m_size.x, m_size.y);
	m_gravityPower = 0;
	m_isGravityOn = true;
	m_collision = false;
	m_isAlive = true;
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

	
	m_position = m_nextPosition;
	m_velocity.y += m_acceleration.y*deltaTime;
	if (m_inAir == false)
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
	m_nextPosition += m_velocity;
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

void Player::setXVelocity(float xVel) {
	m_velocity.x = xVel;
}

void Player::setYVelocity(float yVel) {
	m_velocity.y = yVel;
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
//bool Player::getIsJumping()
//{
//	return m_isJumping;
//}
//void Player::setIsJumping(bool isJumping)
//{
//	m_isJumping = isJumping;
//}

float Player::getGravityPower()
{
	return m_gravityPower;
}
void Player::setGravityPower(float newGravityPower)
{
	m_gravityPower = newGravityPower;
}

bool Player::getInAir() {
	return m_inAir;
}

void Player::setInAir(bool inAir) {
	m_inAir = inAir;
}

void Player::setGravity(float gravity) {
	m_acceleration.y = gravity;
}

float Player::getGravity() {
	return m_acceleration.y;
}

void Player::setBoundingBox(Rect newBox) {
	m_boundingBox = newBox;
}

Rect Player::getBoundingBox() {
	return m_boundingBox;
}

float Player::getX(){
	return m_position.x;
}

void Player::setX(float x){
	m_position.x = x;
}

float Player::getY(){
	return m_position.y;
}

void Player::setY(float y){
	m_position.y = y;
}

float Player::top() {
	return (m_position.y + m_size.y);
}

float Player::right() {
	return m_position.x + m_size.x;
}

Vec2 Player::getNextPos() {
	return m_nextPosition;
}

void Player::setNextPos(Vec2 pos) {
	m_nextPosition = pos;
}

float Player::nextX() {
	return m_nextPosition.x;
}

float Player::nextY() {
	return m_nextPosition.y;
}

float Player::nextRight() {
	return m_nextPosition.x + m_size.x;
}

float Player::nextTop() {
	return m_nextPosition.y + m_size.y;
}

void Player::setNextX(float nextX) {
	m_nextPosition.x = nextX;
}

void Player::setNextY(float nextY) {
	m_nextPosition.y = nextY;
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

//float Player::top() {
//	return m_boundingBox.getMaxY();
//}
//
//float Player::bottom() {
//	return m_boundingBox.getMinY();
//}
//
//float Player::left() {
//	return m_boundingBox.getMinX();
//}
//
//float Player::right() {
//	return m_boundingBox.getMaxX();
//}