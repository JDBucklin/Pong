#include "Scoreboard.h"



Scoreboard::Scoreboard():leftScore(0), rightScore(0)
{}


Scoreboard::~Scoreboard()
{}

void Scoreboard::increaseLeft()
{
	leftScore++;
}

void Scoreboard::increstRight()
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

void Scoreboard::draw(sf::RenderWindow & window)
{
}
