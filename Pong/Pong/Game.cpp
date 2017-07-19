#include "Game.h"
#include <SFML/Graphics.hpp>
#include "Ball.h"

/**
 *	Constructor
 */
Game::Game() :
	window(sf::VideoMode(windowWidth, windowHeight), "Pong"),
	ball(windowWidth / 2, windowHeight / 2),
	scoreBoard(windowWidth / 2),
	leftPaddle(25, windowHeight/2),
	rightPaddle(775, windowHeight/2)
{}

Game::~Game()
{}

/**
 *	Check if either of the players has scored. If so, increment their score
 *	and reposition the ball to the center of the screen.
 */
void Game::checkIfScored()
{
	if (ball.isOutLeft()) {
		scoreBoard.increaseRight();
		ball.resetBall(windowWidth / 2.f, windowHeight / 2.f);
		isPlaying = false;
		scoreBoard.update(windowWidth / 2.f);
	}
	else if (ball.isOutRight(windowWidth)) {
		scoreBoard.increaseLeft();
		ball.resetBall(windowWidth / 2.f, windowHeight / 2.f);
		isPlaying = false;
		scoreBoard.update(windowWidth / 2.f);
	}
}

/**
 *	Checks if one of the players has scored more than the max # of points. 
 *	If there is a winner the scoreboard displays the winner.
 */
void Game::checkForWinner()
{
	if (scoreBoard.getLeftScore() >= maxScore || scoreBoard.getRightScore() >= maxScore) {
		scoreBoard.displayWinner(windowWidth / 2);
	}
}

/**
 *	The main game loop
 */
void Game::play()
{
	sf::Clock clock;
	float deltaTime = 0.0f;
	float totalTime = 0.0f;
	while (window.isOpen()) {
		deltaTime = clock.restart().asSeconds();

		sf::Event event;
		while (window.pollEvent(event)) {
			switch (event.type) {
			case sf::Event::Closed:
				window.close();
				break;
			case sf::Event::KeyPressed:
				if (event.key.code == sf::Keyboard::Space) {
					isPlaying = true;
				}
			default:
				break;
			}
		}
		
		// move the objects and increase score if player scored
		totalTime += deltaTime;
		if (totalTime >= switchTime) {
			leftPaddle.update(totalTime, windowHeight);
			rightPaddle.update(totalTime, windowHeight);
			// only move the ball if the game is playing
			if (isPlaying) {
				ball.updatePosition(totalTime, windowHeight, leftPaddle, rightPaddle);
				checkIfScored();
				checkForWinner();
			}
			totalTime -= switchTime;
		}
		
		// draw objects
		window.clear();
		scoreBoard.draw(window);
		leftPaddle.draw(window);
		rightPaddle.draw(window);
		ball.draw(window);
		window.display();
	}
}
