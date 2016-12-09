#ifndef __BULLET_H__
#define __BULLET_H__

#include "cocos2d.h"

USING_NS_CC;
class Bullet
{
public:
	Sprite *bulletSprite;
	Bullet();

	Point velocity;
	bool isFired;
	int direction;
	int const UP = 0;
	int const LEFT = 1;
	int const DOWN = 2;
	int const RIGHT = 3;
};

#endif