#pragma once
class Vector2
{
public:
	Vector2() : x(0), y(0) {};
	Vector2(float _x, float _y);
	float x;
	float y;
	float magnitude();
	float sqrmagnitude();

};

