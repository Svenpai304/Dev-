#pragma once
#include <SFML/Graphics.hpp>
#include <TinyMathLib/TinyMathLib.h>

class Rigidbody;

class Actor
{
public:
	Actor() {};
	Actor(TinyMathLib::Vector2 position, TinyMathLib::Vector2 scale, float mass, sf::Texture* _texture);
	Rigidbody* rb{};
	sf::Texture* texture{};
	sf::Sprite sprite;
	sf::RenderWindow* window{};

	virtual void Update(float deltaTime);
	virtual void OnCollision(Rigidbody* other);
};

