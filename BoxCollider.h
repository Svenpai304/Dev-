#pragma once
#include "Rigidbody.h"

class BoxCollider
{
public:
	BoxCollider() : xHalf(0), yHalf(0) {};
	BoxCollider(Rigidbody* rigidbody, float _xHalf, float _yHalf);
	Rigidbody* rb{};
	float xHalf, yHalf;

	void OnCollision(Rigidbody other);
	bool CheckCollision(BoxCollider other);
};

