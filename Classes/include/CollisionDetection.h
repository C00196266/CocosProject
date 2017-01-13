#ifndef COLLISIONDETECTION_H
#define COLLISIONDETECTION_H

#include "cocos2d.h"

USING_NS_CC;

class CollisionDetection {
public:
	CollisionDetection();

	bool boundingBoxCollision(float object1X, float object1Y, float object1Width, float object1Height, float object2X, float object2Y, float object2Width, float object2Height);
	bool boundingBoxCollision(Vec2 object1pos, Vec2 object1size, Vec2 object2pos, Vec2 object2size);
	bool boundingBoxCollision(Vec2 object1pos, float object1Width, float object1Height, Vec2 object2pos, float object2Width, float object2Height);
	bool boundingBoxCollision(Rect object1rect, Rect object2rect);

	// collides with specifically the top of an object

	// TRY NOT TO USE THESE THEY DON'T WORK PROPERLY
	// LEAVING HERE IN CASE OF POTENTIAL SOLUTION
	bool boundingBoxCollisionTop(Rect object1rect, Rect object2rect);
	bool boundingBoxCollisionLeft(Rect object1rect, Rect object2rect);
	bool boundingBoxCollisionRight(Rect object1rect, Rect object2rect);
	bool boundingBoxCollisionBottom(Rect object1rect, Rect object2rect);

	bool VerticalCollision();

	//bool collisionPlayerTiles(Player thePlayer, shared_ptr<Tile> aTile);


private:
};

#endif
