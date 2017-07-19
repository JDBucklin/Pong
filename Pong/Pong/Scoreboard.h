#pragma once
#include <SFML/Graphics.hpp>

class Scoreboard
{
public:
	Scoreboard(float xPos);
	~Scoreboard();
	void increaseLeft();
	void increaseRight();
	int getLeftScore();
	int getRightScore();
	void displayWinner(float xPos);
	void update(float xPos);
	void draw(sf::RenderWindow& window);
private:
	int leftScore;
	int rightScore;
	sf::Font font;
	sf::Text text;
};

