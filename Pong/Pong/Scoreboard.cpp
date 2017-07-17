#include "Scoreboard.h"
#include <string>
#include <iostream>

Scoreboard::Scoreboard(float xPos) :leftScore(0), rightScore(0)
{
	if (!font.loadFromFile("cour.ttf")) {
		fontLoaded = false;
		std::cout << "Error: Failed to load scoreboard font" << std::endl;
	}
	else {
		fontLoaded = true;
		text.setFont(font);
		text.setCharacterSize(80);
		text.setFillColor(sf::Color::White);
		update(xPos);
	}
}

Scoreboard::~Scoreboard()
{}

void Scoreboard::increaseLeft()
{
	leftScore++;
}

void Scoreboard::increaseRight()
{
	rightScore++;
}

int Scoreboard::getLeftScore()
{
	return leftScore;
}

int Scoreboard::getRightScore()
{
	return rightScore;
}

void Scoreboard::displayWinner(float xPos)
{
	if (leftScore > rightScore) {
		text.setString("Left Player Wins");
	}
	else {
		text.setString("Right Player Wins");
	}
	text.setCharacterSize(50);
	text.setOrigin(text.getLocalBounds().width / 2.0f, text.getLocalBounds().height / 2.0f);
	text.setPosition(xPos, 0.f);
}

void Scoreboard::update(float xPos) {
	std::string currentScore = std::to_string(leftScore) + "\t" + std::to_string(rightScore);
	text.setString(currentScore);
	text.setOrigin(text.getLocalBounds().width / 2.0f, text.getLocalBounds().height / 2.0f);
	text.setPosition(xPos, 0.f);
}

void Scoreboard::draw(sf::RenderWindow & window)
{
	if (!fontLoaded) {
		return;
	}
	window.draw(text);
}
