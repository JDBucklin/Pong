#include "Game.h"
#include <SFML/Graphics.hpp>
#include "Ball.h"

Game::Game() :
	window(sf::VideoMode(windowWidth, windowHeight), "Pong"),
	ball(windowWidth / 2, windowHeight / 2),
	leftPaddle(25, windowHeight/2),
	rightPaddle(775, windowHeight/2)
{}

Game::~Game()
{}

void Game::checkIfScored()
{
	if (ball.isOutLeft()) {
		scoreBoard.increaseLeft();
		ball.resetBall(windowWidth / 2, windowHeight / 2);
		isPlaying = false;
	}
	else if (ball.isOutRight(windowWidth)) {
		scoreBoard.increstRight();
		ball.resetBall(windowWidth / 2, windowHeight / 2);
		isPlaying = false;
	}
}

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
			}
			totalTime -= switchTime;
		}
		
		// draw objects
		window.clear();
		leftPaddle.draw(window);
		rightPaddle.draw(window);
		ball.draw(window);
		window.display();
	}
}
