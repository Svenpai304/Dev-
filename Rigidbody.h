#pragma once

class BoxCollider;

#include "Actor.h"
#include <TinyMathLib/TinyMathLib.h>

class Rigidbody
{
public:
	Rigidbody() : position(TinyMathLib::Vector2(0, 0)), mass(1) {};
	Rigidbody(TinyMathLib::Vector2 _position, float _mass);
	Actor* actor{};
	BoxCollider* collider{};
	TinyMathLib::Vector2 position;
	TinyMathLib::Vector2 velocity;
	float friction = 0.99f;
	float mass = 1;
	float gravity = 100;
	bool gravityOn = false;

	void Update(float deltaTime);
	void AddForce(TinyMathLib::Vector2 force);
};
