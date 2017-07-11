#include <iostream>
#include "Ball.h"
#include <SFML/Graphics.hpp>

const int HEIGHT = 400;
const int WIDTH = 800;
const float BALL_RADIUS = 10.f;

int main() {
	sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), "Pong");
	Ball ball(WIDTH / 2, HEIGHT / 2);

	sf::Clock clock;
	float deltaTime = 0.0f;
	float switchTime = 1.f / 30.f;
	float totalTime = 0.0f;
	sf::Vector2f direction(0, 1);
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
			ball.updatePosition(totalTime, HEIGHT, WIDTH);
			totalTime -= switchTime;
		}
		
		// draw objects
		window.clear();
		ball.draw(window);
		window.display();
	}

	return 0;
}