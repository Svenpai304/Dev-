#pragma once
#include "BoxCollider.h"
#include <list>
class CollisionChecker
{
public:
	void CheckAllCollision();
	void AddCollider(BoxCollider* collider);

	std::list<BoxCollider*> colliders;
};

