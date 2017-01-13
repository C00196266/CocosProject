#pragma once
#include "cocos2d.h"
#include "Player.h"

USING_NS_CC;

class Spikes {
private:
	Vec2 m_pos;
	Vec2 m_size;

public:
	Spikes();

	Spikes(Vec2 position);

	Vec2 getPos();

	void setSize(Vec2 size);
	Vec2 getSize();

	Sprite *sprite;

	void CheckCollisionWithPlayer(Player * player);
};