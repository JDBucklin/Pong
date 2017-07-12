#include "Game.h"
#include <SFML/Graphics.hpp>
#include "Ball.h"

Game::Game() :
	window(sf::VideoMode(windowWidth, windowHeight), "Pong"),
	ball(windowWidth/2, windowHeight/2)
{}

Game::~Game()
{}

void Game::checkIfScored()
{
	if (ball.isOutLeft()) {
		scoreBoard.increaseLeft();
		ball.resetBall(windowWidth / 2, windowHeight / 2);
	}
	else if (ball.isOutRight(windowWidth)) {
		scoreBoard.increstRight();
		ball.resetBall(windowWidth / 2, windowHeight / 2);
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
			default:
				break;
			}
		}

		// move the objects and increase score if player scored
		totalTime += deltaTime;
		if (totalTime >= switchTime) {
			ball.updatePosition(totalTime, windowHeight);
			checkIfScored();
			totalTime -= switchTime;
		}
		
		// draw objects
		window.clear();
		ball.draw(window);
		window.display();
	}
}
