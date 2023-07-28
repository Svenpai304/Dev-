// TinyMathLib.cpp : Defines the functions for the static library.
//
#include "TinyMathLib.h"
#include <cmath>

namespace TinyMathLib {

	float Mathf::Abs(float value) {
		if (value > 0) return value;
		if (value < 0) return value * -1;
		else return value;
	}

	Vector2::Vector2(float _x, float _y) {
		x = _x;
		y = _y;
	}

	float Vector2::magnitude() {
		return sqrt(x * x + y * y);
	}

	float Vector2::sqrmagnitude() {
		return x * x + y * y;
	}

	bool Vector2::operator==(const Vector2& other) const {
		return x == other.x && y == other.y;
	}

	Vector2 Vector2::operator+(const Vector2& other) const {
		return Vector2(x + other.x, y + other.y);
	}

	Vector2 Vector2::operator*(const float& factor) const {
		return Vector2(x * factor, y * factor);
	}
}
