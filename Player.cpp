#include "Player.h"
#include "Enemy.h"
#include <typeinfo>
#include "Rigidbody.h"
#include "BoxCollider.h"

Player::Player(TinyMathLib::Vector2 position, TinyMathLib::Vector2 scale, float mass, sf::Texture* _texture) {
	rb = new Rigidbody(position, mass);
	rb->collider->xHalf = scale.x * 1000;
	rb->collider->yHalf = scale.y * 1000;
	rb->mass = mass;
	rb->dragCoefficient = 0.2f;
	rb->actor = this;
	texture = _texture;
	sprite.setTexture(*texture);
	sprite.setScale(scale.x, scale.y);
	sprite.setOrigin(texture->getSize().x / 2, texture->getSize().y / 2);
	sprite.setPosition(position.x, position.y);
}
void Player::OnCollision(Rigidbody* other) {

}
