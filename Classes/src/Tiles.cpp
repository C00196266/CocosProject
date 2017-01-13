#include "Tiles.h"

Tiles::Tiles()
{
	m_pos = Vec2(0, 0);
	m_size = Vec2(50, 50);
}

Tiles::Tiles(Vec2 position)
{
	m_pos = position;
	m_size = Vec2(50, 50);
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

void Tiles::CheckCollisionWithPlayer(Player * player) {
	if (player->getX() < m_pos.x + m_size.x && player->right() > m_pos.x) {
		if (player->getY() >= m_pos.y + m_size.y && player->nextY() <= m_pos.y + m_size.y && player->top() > m_pos.y + m_size.y) {
			player->setNextY(m_pos.y + m_size.y);
			player->setInAir(false);
			player->setYVelocity(0);
		}
		else if (player->getY() >= m_pos.y + m_size.y && player->nextY() > m_pos.y + m_size.y && player->top() > m_pos.y + m_size.y){
			player->setInAir(true);
		}

		if (player->top() <= m_pos.y && player->nextTop() >= m_pos.y && player->getY() < m_pos.y) {
			player->setNextY(m_pos.y - player->getSize().y);
			player->setYVelocity(0);
		}
	}

	if ((player->getY() < m_pos.y + m_size.y && player->top() > m_pos.y))
	{
		// left side of player colliding with right side of tile
		if (player->getX() >= m_pos.x + m_size.x && player->nextX() < m_pos.x + m_size.x && player->right() > m_pos.x + m_size.x) {
			player->setNextX(m_pos.x + m_size.x);
			player->setXVelocity(0);
		}
		// right side of player - left side of tile
		if (player->right() <= m_pos.x && player->nextRight() > m_pos.x && player->getX() < m_pos.x) {
			player->setNextX(m_pos.x - player->getSize().x);
			player->setXVelocity(0);
		}
	}
}