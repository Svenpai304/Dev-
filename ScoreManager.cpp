#include "ScoreManager.h"
#include <sstream>

ScoreManager::ScoreManager() {
	drawPosition = TinyMathLib::Vector2(10, 10);
	font.loadFromFile("PublicPixel-z84yD.ttf");
	scoreText.setFont(font);
	scoreText.setCharacterSize(24);
	scoreText.setFillColor(sf::Color::Black);
	scoreText.setStyle(sf::Text::Bold | sf::Text::Underlined);
	scoreText.setPosition(drawPosition.x, drawPosition.y);
}


void ScoreManager::DrawScore() {
	std::stringstream ss;
	ss << score;
	scoreText.setString(ss.str());
	window->draw(scoreText);
}

void ScoreManager::DrawFinalScore() {

	if (scoreText.getCharacterSize() != 60) {
		scoreText.setCharacterSize(60);
		drawPosition = TinyMathLib::Vector2((window->getSize().x / 2) - (scoreText.getCharacterSize() / 2), 200);
		scoreText.setPosition(drawPosition.x, drawPosition.y);
	}

	std::stringstream ss;
	ss << score;
	scoreText.setString(ss.str());
	window->draw(scoreText);
}