#include "Vector2.h"
#include <cmath>

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
