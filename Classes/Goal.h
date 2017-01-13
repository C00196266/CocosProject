#pragma once

#include "cocos2d.h"

USING_NS_CC;

class Goal {
private:
	Vec2 m_pos;
	Vec2 m_size;

	Rect m_boundingBox;

public:
	Goal();

	Goal(Vec2 position);

	Vec2 getPos();

	void setSize(Vec2 size);
	Vec2 getSize();

	bool collsion(Vec2 m_pos, Vec2 m_size);
	Sprite *sprite;

};