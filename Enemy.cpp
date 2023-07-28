#include "Enemy.h"
#include "Player.h"
#include <typeinfo>
#include "Rigidbody.h"
#include "BoxCollider.h"
#include "EnemyManager.h"
#include "ScoreManager.h"
#include <iostream>

Enemy::Enemy(TinyMathLib::Vector2 position, TinyMathLib::Vector2 scale, float mass, sf::Texture* _texture) {
	rb = new Rigidbody(position, mass);
	rb->collider->xHalf = scale.x * 150;
	rb->collider->yHalf = scale.y * 150;
	rb->mass = mass;
	rb->gravity = 150;
	rb->actor = this;
	texture = _texture;
	sprite.setTexture(*texture);
	sprite.setScale(scale.x, scale.y);
	sprite.setOrigin(texture->getSize().x / 2, texture->getSize().y / 2);
	sprite.setPosition(position.x, position.y);
}
void Enemy::OnCollision(Rigidbody* other) {
	std::cout << "Collision";
	if (typeid(*other->actor) == typeid(Enemy)) {
	}
	else if (typeid(*other->actor) == typeid(Player)) {
		manager->scoreManager->score += 1;
		manager->DestroyEnemy(this);
	}
}
void Enemy::Update(float deltaTime) {
	rb->Update(deltaTime);

	sprite.setPosition(rb->position.x, rb->position.y);
	window->draw(sprite);

	if (rb->position.y > manager->window->getSize().y + 100) {
		manager->DestroyEnemy(this);
	}
}

bool Enemy::operator==(const Enemy& other) const {
	return rb->position == other.rb->position;
}