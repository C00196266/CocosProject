#include "ScorePickup.h"

USING_NS_CC;

ScorePickup::ScorePickup()
{
	m_isAlive = true;
	m_pos = Vec2(0, 0);
	m_size = Vec2(50, 50);
	m_scoreValue = 10;
	m_boundingBox = Rect(m_pos.x, m_pos.y, 70, 70);
}

ScorePickup::ScorePickup(Vec2 position)
{
	m_pos = position;
	m_size = Vec2(50, 50);
	m_isAlive = true;
	m_scoreValue = 10;
	m_boundingBox = Rect(m_pos.x, m_pos.y, 70, 70);
}

Vec2 ScorePickup::getPos() {
	return m_pos;
}

void ScorePickup::setSize(Vec2 size) {
	m_size = size;
}

Vec2 ScorePickup::getSize() {
	return m_size;
}

int ScorePickup::getScoreValue() {
	return m_scoreValue;
}

bool ScorePickup::getAlive() {
	return m_isAlive;
}

void ScorePickup::setAlive(bool aliveState) {
	m_isAlive = aliveState;
}
