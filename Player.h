#pragma once
#include "Actor.h"
class Player :
    public Actor
{
public:
    Player() {};
    Player(TinyMathLib::Vector2 position, TinyMathLib::Vector2 scale, float mass, sf::Texture* _texture);
    void OnCollision(Rigidbody* other);
};

