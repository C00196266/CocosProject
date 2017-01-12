#include "Goal.h"

Goal::Goal()
{
	m_pos = Vec2(0, 0);
	m_size = Vec2(76, 60);
}

Goal::Goal(Vec2 position)
{
	m_pos = position;
	m_size = Vec2(76, 60);
}

Vec2 Goal::getPos()
{
	return m_pos;
}

Vec2 Goal::getSize()
{
	return m_size;
}

void Goal::setSize(Vec2 size)
{
	m_size = size;
}