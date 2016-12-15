#include "Spikes.h"

Spikes::Spikes()
{
	m_pos = Vec2(0, 0);
	m_size = Vec2(50, 50);
}

Spikes::Spikes(Vec2 position)
{
	m_pos = position;
	m_size = Vec2(50, 50);
}

Vec2 Spikes::getPos() {
	return m_pos;
}

void Spikes::setSize(Vec2 size) {
	m_size = size;
}

Vec2 Spikes::getSize() {
	return m_size;
}