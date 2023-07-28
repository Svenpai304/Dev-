#include "CollisionChecker.h"

void CollisionChecker::CheckAllCollision() {

	auto itr = colliders.begin();
	auto other = colliders.begin();
	for (auto i = 0; i < colliders.size(); i++) {
		
		other = colliders.begin();
		for (auto n = 0; n < colliders.size(); n++) {
			if (n != i) {
				BoxCollider* collider = *itr;
				collider->CheckCollision(**other);
			}
			other++;
		}
		itr++;
	}

}

void CollisionChecker::AddCollider(BoxCollider* collider) {
	colliders.push_back(collider);
}
