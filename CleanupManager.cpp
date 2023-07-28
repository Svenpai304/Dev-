#include "CleanupManager.h"
#include "EnemyManager.h"
#include "CollisionChecker.h"

void CleanupManager::CleanAllQueued() {
	auto itr = enemies.begin();
	for (auto n = 0; n < enemies.size(); n++) {
		Enemy* enemy = *itr;
		enemyManager->enemies.remove(enemy);
		collisionChecker->colliders.remove(enemy->rb->collider);
		itr++;
	}
}

void CleanupManager::AddEnemyToQueue(Enemy* enemy) {
	if (enemy != NULL) {
		enemies.push_front(enemy);
	}
}
