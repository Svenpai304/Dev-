#pragma once

class EnemyManager;

#include "Actor.h"
class Enemy :
    public Actor
{
public:
    Enemy() {};
    Enemy(TinyMathLib::Vector2 position, TinyMathLib::Vector2 scale, float mass, sf::Texture* _texture);
    EnemyManager* manager{};
    void OnCollision(Rigidbody* other);
    void Update(float deltaTime);

    bool operator==(const Enemy& other) const;
};