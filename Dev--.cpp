#include <SFML/Graphics.hpp>
#include <iostream>
#include "Player.h"
#include "Rigidbody.h"
#include "CollisionChecker.h"
#include "EnemyManager.h"
#include "ScoreManager.h"
#include "CleanupManager.h"
int main()
{
    float moveForce = 40;
    float playerMass = 1;
    float playerSpawnHeight = 600;
    TinyMathLib::Vector2 playerScale = TinyMathLib::Vector2(0.1, 0.1);


    sf::RenderWindow* window;
    window = new sf::RenderWindow(sf::VideoMode(1000, 750), "SFML!!");
    window->setFramerateLimit(60);
    float deltaTime = static_cast<float>(1) / 60;

    CleanupManager cleanupManager;

    CollisionChecker collisionChecker;
    cleanupManager.collisionChecker = &collisionChecker;

    ScoreManager scoreManager;
    scoreManager.window = window;

    sf::Texture* enemyTexture = new sf::Texture;
    enemyTexture->loadFromFile("11-hammer-png-image-picture.png");
    EnemyManager enemyManager;
    enemyManager.enemyTexture = *enemyTexture;
    enemyManager.window = window;
    enemyManager.collisionChecker = &collisionChecker;
    enemyManager.scoreManager = &scoreManager;
    enemyManager.cleanupManager = &cleanupManager;
    cleanupManager.enemyManager = &enemyManager;

    sf::Texture* playerTexture = new sf::Texture;
    playerTexture->loadFromFile("wicker-basket-png--2006.png");
    Player* player = new Player(TinyMathLib::Vector2(window->getSize().x * 0.5, playerSpawnHeight), playerScale, playerMass, playerTexture);
    player->window = window;
    collisionChecker.AddCollider(player->rb->collider);

    while (window->isOpen()) {

        if (!enemyManager.finished) {
            window->clear(sf::Color::White);
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) || sf::Keyboard::isKeyPressed(sf::Keyboard::A)) player->rb->AddForce(TinyMathLib::Vector2(-moveForce, 0));
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) || sf::Keyboard::isKeyPressed(sf::Keyboard::D)) player->rb->AddForce(TinyMathLib::Vector2(moveForce, 0));

            player->Update(deltaTime);
            enemyManager.UpdateAll(deltaTime);
            collisionChecker.CheckAllCollision();
            cleanupManager.CleanAllQueued();
            scoreManager.DrawScore();

        }
        else {
            if (scoreManager.score < 8) {
                window->clear(sf::Color::Red);
            }
            else {
                window->clear(sf::Color::Green);
            }
            scoreManager.DrawFinalScore();
        }
        sf::Event event;
        while (window->pollEvent(event)) {
             if (event.type == sf::Event::Closed) window->close();
             if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape) window->close();
        }

        window->display();
    }
    return 0;
}
