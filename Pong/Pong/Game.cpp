#include "Game.h"
#include <SFML/Graphics.hpp>
#include "Ball.h"

Game::Game()
{
}

Game::~Game()
{
}

void Game::play()
{
	sf::RenderWindow window(sf::VideoMode(windowWidth, windowHeight), "Pong");
	Ball ball(windowWidth / 2, windowHeight / 2);

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

		// check if object positions need to be updated
		totalTime += deltaTime;
		if (totalTime >= switchTime) {
			ball.updatePosition(totalTime, windowHeight, windowWidth);
			totalTime -= switchTime;
		}

		// draw objects
		window.clear();
		ball.draw(window);
		window.display();
	}
}
