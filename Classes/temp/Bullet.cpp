#include "Bullet.h"

Bullet::Bullet() {
	bulletSprite = Sprite::create("GameScreen/bullet.png");
	bulletSprite->setPosition(300, 300);
	bulletSprite->setAnchorPoint(Vec2(0.5, 0));

	velocity = Point(-0, 0);
	isFired = false;
	direction = DOWN;
}