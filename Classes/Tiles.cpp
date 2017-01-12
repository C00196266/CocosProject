#include "Tiles.h"

Tiles::Tiles()
{
	m_pos = Vec2(0, 0);
	m_size = Vec2(50, 50);
	m_boundingBox = Rect(m_pos.x, m_pos.y, m_size.x, m_size.y);
}

Tiles::Tiles(Vec2 position)
{
	m_pos = position;
	m_size = Vec2(50, 50);
	m_boundingBox = Rect(m_pos.x, m_pos.y, m_size.x, m_size.y);
}

Vec2 Tiles::getPos() {
	return m_pos;
}

void Tiles::setSize(Vec2 size) {
	m_size = size;
}

Vec2 Tiles::getSize() {
	return m_size;
}

void Tiles::setBoundingBox(Rect newBoudingBox) {
	m_boundingBox = newBoudingBox;
}

Rect Tiles::getBoundingBox() {
	return m_boundingBox;
}