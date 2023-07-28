#pragma once
#include <list>

class Enemy;
class EnemyManager;
class CollisionChecker;

class CleanupManager
{
public:
	void CleanAllQueued();
	void AddEnemyToQueue(Enemy* enemy);

	std::list<Enemy*> enemies;

	EnemyManager* enemyManager{};
	CollisionChecker* collisionChecker{};

};

