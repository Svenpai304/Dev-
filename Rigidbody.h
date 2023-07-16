#pragma once
#include "Vector2.h"
class Rigidbody
{
public:
	Rigidbody(Vector2 _position, float _mass) {};
	Vector2 position;
	Vector2 velocity;
	float friction;
	float mass;

	void Update(float deltaTime);
	void AddForce(Vector2 force);

};

