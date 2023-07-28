#pragma once
#include <list>
#include <SFML/Graphics.hpp>
#include "Enemy.h"
#include <chrono>

class CollisionChecker;
class ScoreManager;
class CleanupManager;

class EnemyManager
{
public:
	EnemyManager();
	void UpdateAll(float deltaTime);
	void CreateEnemy();
	void DestroyEnemy(Enemy* enemy);

	int enemiesSpawned = 0;
	bool finished = false;
	std::chrono::time_point<std::chrono::steady_clock> prevTime = std::chrono::steady_clock::now();

	TinyMathLib::Vector2 enemyScale = TinyMathLib::Vector2(0.1, 0.1);
	float enemyMass = 1;
	sf::Texture enemyTexture;
	sf::RenderWindow* window{};
	CollisionChecker* collisionChecker{};
	ScoreManager* scoreManager{};
	CleanupManager* cleanupManager{};

	std::list<Enemy*> enemies;
};

