#pragma once
#include <SFML/Graphics.hpp>
class Scoreboard
{
public:
	Scoreboard();
	~Scoreboard();
	void increaseLeft();
	void increstRight();
	int getLeftScore();
	int getRightScore();
	void draw(sf::RenderWindow& window);
private:
	int leftScore;
	int rightScore;
};

