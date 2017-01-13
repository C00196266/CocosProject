
#pragma once
#include "cocos2d.h"

USING_NS_CC;

class Tiles {
private:
	Vec2 m_pos;
	Vec2 m_size;

	Rect m_boundingBox;

public:
	Tiles();

	Tiles(Vec2 position);

	Vec2 getPos();

	void setSize(Vec2 size);
	Vec2 getSize();

	Sprite *sprite;

	void setBoundingBox(Rect newBoundingBox);
	Rect getBoundingBox();
};