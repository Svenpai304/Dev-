#include "EnemyManager.h"
#include "Enemy.h"
#include "Rigidbody.h"
#include "CollisionChecker.h"
#include "CleanupManager.h"
#include <time.h>

EnemyManager::EnemyManager() {
	srand(time(NULL));
}

void EnemyManager::UpdateAll(float deltaTime) {
	if (enemiesSpawned < 10) {
		if (std::chrono::steady_clock::now() - prevTime >= std::chrono::seconds(1)) {
			prevTime = std::chrono::steady_clock::now();
			CreateEnemy();
			enemiesSpawned += 1;
		}
	}
	else if (enemies.size() == 0) {
		finished = true;
		return;
	}

	auto itr = enemies.begin();
	for (auto i = 0; i < enemies.size(); i++) {
		Enemy* enemy = *itr;
		enemy->Update(deltaTime);
		itr++;
	}
}

void EnemyManager::CreateEnemy() {
	TinyMathLib::Vector2 position = TinyMathLib::Vector2(std::rand() % 800 + 50, -200);
	Enemy* enemy = new Enemy(position, enemyScale, enemyMass, &enemyTexture);
	enemy->rb->gravityOn = true;
	enemy->manager = this;
	enemy->window = window;
	collisionChecker->AddCollider(enemy->rb->collider);

	enemies.push_back(enemy);

	enemy->rb->AddForce(TinyMathLib::Vector2((std::rand() % 100000) - 50000, 0));
}

void EnemyManager::DestroyEnemy(Enemy* enemy) {
	cleanupManager->AddEnemyToQueue(enemy);
}