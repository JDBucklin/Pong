#pragma once
#include <SFML/Graphics.hpp>
#include "Ball.h"
#include "Scoreboard.h"
#include "Paddle.h"

class Game
{
public:
	Game();
	~Game();
	void play();
	void checkIfScored();
	void checkForWinner(float xPos);
private:
	//Game variables
	int windowHeight = 400;
	int windowWidth = 800;
	int maxScore = 3;
	float switchTime = 1.f / 60.f;
	bool isPlaying = false;

	//Game objects
	sf::RenderWindow window;
	Ball ball;
	Scoreboard scoreBoard;
	Paddle leftPaddle;
	Paddle rightPaddle;
};

