#pragma once
#include <SFML/Graphics.hpp>
#include "Ball.h"
#include "Scoreboard.h"

class Game
{
public:
	Game();
	~Game();
	void play();
	void checkIfScored();
private:
	//Game variables
	int windowHeight = 400;
	int windowWidth = 800;
	float switchTime = 1.f / 60.f;

	sf::RenderWindow window;
	Ball ball;
	Scoreboard scoreBoard;
};

