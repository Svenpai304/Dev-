#include "Rigidbody.h"
#include "BoxCollider.h"
Rigidbody::Rigidbody(TinyMathLib::Vector2 _position, float _mass) {
	position = _position;
	mass = _mass;

	collider = new BoxCollider(this, 1, 1);
}

void Rigidbody::Update(float deltaTime) {

	if (gravityOn) {
		velocity.y += gravity * deltaTime;
	}

	position = position + (velocity * deltaTime);

	velocity = velocity * friction;

	if ((position.x < 50 && velocity.x < 0) || (position.x > actor->window->getSize().x - 50 && velocity.x > 0)) {
		velocity.x *= -1;
	}
}

void Rigidbody::AddForce(TinyMathLib::Vector2 force) {
	velocity.x += force.x / mass;
	velocity.y += force.y / mass;
}