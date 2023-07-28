#pragma once

namespace TinyMathLib {

	class Mathf
	{
	public:

		static float Abs(float value);
	};

	class Vector2
	{
	public:
		Vector2() : x(0), y(0) {};
		Vector2(float _x, float _y);
		float x;
		float y;
		float magnitude();
		float sqrmagnitude();

		bool operator==(const Vector2& other) const;
		Vector2 operator+(const Vector2& other) const;
		Vector2 operator*(const float& factor) const;
	};
}