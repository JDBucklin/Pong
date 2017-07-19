#include "Scoreboard.h"
#include <string>
#include <iostream>

/**
 *	Constructor
 *	
 *	@param xPos the x position to place the scoreboard
 */
Scoreboard::Scoreboard(float xPos) :leftScore(0), rightScore(0)
{
	if (!font.loadFromFile("cour.ttf")) {
		std::cout << "Error: Failed to load scoreboard font" << std::endl;
	}
	else {
		text.setFont(font);
		text.setCharacterSize(80);
		text.setFillColor(sf::Color::White);
		update(xPos);
	}
}

Scoreboard::~Scoreboard()
{}

/**
 *	Increase the left player score by one
 */
void Scoreboard::increaseLeft()
{
	leftScore++;
}

/**
 *	Increase the right player score by one
 */
void Scoreboard::increaseRight()
{
	rightScore++;
}

/**
 *	Get the left player's score
 *	
 *	@return the left player's score
 */
int Scoreboard::getLeftScore()
{
	return leftScore;
}

/**
 *	Get the right player's score
 *	
 *	@return the right player's score
 */
int Scoreboard::getRightScore()
{
	return rightScore;
}

/**
 *	Display the winner of the game
 */
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

/**
 *	Update the scoreboard
 *	@param xPos the x position to draw the window at
 */
void Scoreboard::update(float xPos) {
	std::string currentScore = std::to_string(leftScore) + "\t" + std::to_string(rightScore);
	text.setString(currentScore);
	text.setOrigin(text.getLocalBounds().width / 2.0f, text.getLocalBounds().height / 2.0f);
	text.setPosition(xPos, 0.f);
}

/**
 *	Draw the scoreboard to the given window
 *	
 *	@param window the window the draw the scoreboard in
 */
void Scoreboard::draw(sf::RenderWindow & window)
{
	window.draw(text);
}
