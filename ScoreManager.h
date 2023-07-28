#pragma once
#include <TinyMathLib/TinyMathLib.h>
#include <SFML/Graphics.hpp>

class ScoreManager
{
public:
	ScoreManager();
	int score = 0;
	TinyMathLib::Vector2 drawPosition;
	sf::RenderWindow* window{};
	sf::Text scoreText;
	sf::Font font;
	void DrawScore();
	void DrawFinalScore();
};

