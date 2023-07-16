#include "Rigidbody.h"

Rigidbody::Rigidbody(Vector2 _position, float _mass) {
	position = _position;
	mass = _mass;
}

void Rigidbody::Update(float deltaTime) {
	position.x += velocity.x * deltaTime;
	position.y += velocity.y * deltaTime;

	velocity.x *= friction;
	velocity.y *= friction;
}

void Rigidbody::AddForce(Vector2 force) {
	velocity.x += force.x / mass;
	velocity.y += force.y / mass;
}