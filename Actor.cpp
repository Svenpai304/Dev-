#include "Actor.h"
#include "Rigidbody.h"
#include "BoxCollider.h"
Actor::Actor(TinyMathLib::Vector2 position, TinyMathLib::Vector2 scale, float mass, sf::Texture* _texture) {
	rb = new Rigidbody(position, mass);
	rb->collider->xHalf = scale.x;
	rb->collider->yHalf = scale.y;
	rb->mass = mass;
	rb->actor = this;
	texture = _texture;
	sprite.setTexture(*texture);
	sprite.setScale(scale.x, scale.y);
	sprite.setOrigin(texture->getSize().x / 2, texture->getSize().y / 2);
	sprite.setPosition(position.x, position.y);
}

void Actor::Update(float deltaTime) {
	rb->Update(deltaTime);
	sprite.setPosition(rb->position.x, rb->position.y);
	window->draw(sprite);
	

}

void Actor::OnCollision(Rigidbody* other) {

}