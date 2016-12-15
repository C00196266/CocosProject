#include "CollisionDetection.h"

CollisionDetection::CollisionDetection() {

}

bool CollisionDetection::boundingBoxCollision(float object1X, float object1Y, float object1Width, float object1Height, float object2X, float object2Y, float object2Width, float object2Height) {
	if (object1X + object1Width <= object2X || object1X >= object2X + object2Width ||
		object1Y + object1Height <= object2Y || object1Y >= object2Y + object2Height) {
		return false;
	}
	else {
		return true;
	}
}

bool CollisionDetection::boundingBoxCollision(Vec2 object1pos, Vec2 object1size, Vec2 object2pos, Vec2 object2size) {
	if (object1pos.x + object1size.x <= object2pos.x || object1pos.x >= object2pos.x + object2size.x ||
		object1pos.y + object1size.y <= object2pos.y || object1pos.y >= object2pos.y + object2size.y)
	{
		return false;
	}
	else {
		return true;
	}
}

bool CollisionDetection::boundingBoxCollision(Vec2 object1pos, float object1Width, float object1Height, Vec2 object2pos, float object2Width, float object2Height) {
	if (object1pos.x + object1Width <= object2pos.x || object1pos.x >= object2pos.x + object2Width ||
		object1pos.y + object1Height <= object2pos.y || object1pos.y >= object2pos.y + object2Height)
	{
		return false;
	}
	else {
		return true;
	}
}

bool CollisionDetection::boundingBoxCollision(Rect object1rect, Rect object2rect) {
	if (object1rect.intersectsRect(object2rect)) {
		return true;
	}
	else {
		return false;
	}
}

bool CollisionDetection::boundingBoxCollisionTop(Rect object1rect, Rect object2rect) {
	if (object1rect.intersectsRect(object2rect)) {
		if (object1rect.getMaxY() > object2rect.getMinY() && object1rect.getMaxY() < object2rect.getMidY()) {
			return true;
		}
		else {
			return false;
		}
	}
}

bool CollisionDetection::boundingBoxCollisionLeft(Rect object1rect, Rect object2rect) {
	if (object1rect.intersectsRect(object2rect)) {
		if (object1rect.getMaxX() > object2rect.getMinX() && object1rect.getMaxX() < object2rect.getMidX()) {
			return true;
		}
		else {
			return false;
		}
	}
}

bool CollisionDetection::boundingBoxCollisionRight(Rect object1rect, Rect object2rect) {
	if (object1rect.intersectsRect(object2rect)) {
		if (object1rect.getMinX() < object2rect.getMaxX() && object1rect.getMaxX() > object2rect.getMidX()) {
			return true;
		}
		else {
			return false;
		}
	}
}

bool CollisionDetection::boundingBoxCollisionBottom(Rect object1rect, Rect object2rect) {
	if (object1rect.intersectsRect(object2rect)) {
		if (object1rect.getMinY() < object2rect.getMaxY() && object1rect.getMaxY() > object2rect.getMidY()) {
			return true;
		}
		else {
			return false;
		}
	}
}