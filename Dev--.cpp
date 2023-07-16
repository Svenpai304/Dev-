#include <SFML/Graphics.hpp>

int main()
{
    sf::RenderWindow* window;
    window = new sf::RenderWindow(sf::VideoMode(1000, 750), "SFML!!");

    while (window->isOpen()) {

        sf::Event event;
        while (window->pollEvent(event)) {
            if (event.type == sf::Event::Closed) window->close();
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape) window->close();
        }
        window->clear(sf::Color::White);
        window->display();
    }
    return 0;
}
