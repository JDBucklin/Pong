#include <iostream>
#include <SFML/Graphics.hpp>

const int HEIGHT = 400;
const int WIDTH = 800;
const float BALL_RADIUS = 10.f;

int main() {
	sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), "Pong");
	sf::CircleShape ball(BALL_RADIUS);
	ball.setOrigin(sf::Vector2f(ball.getRadius(), ball.getRadius()));
	ball.setPosition(sf::Vector2f(WIDTH/2, HEIGHT/2));

	sf::Clock clock;
	float deltaTime = 0.0f;
	float switchTime = 1.f / 30.f;
	float totalTime = 0.0f;
	float speed = 10.f;
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

		totalTime += deltaTime;
		if (totalTime >= switchTime) {
			//update ball position
			ball.move(speed*direction.x, speed*direction.y);

			//check for ball collision
			//bottom of window
			if (ball.getPosition().y + BALL_RADIUS > HEIGHT) {
				direction.y = -1;
				ball.setPosition(ball.getPosition().x, HEIGHT - BALL_RADIUS);
			}
			//top of window
			if (ball.getPosition().y - BALL_RADIUS < 0) {
				direction.y = 1;
				ball.setPosition(ball.getPosition().x, BALL_RADIUS);
			}
			
			totalTime -= switchTime;
			std::cout << totalTime << std::endl;
		}
		window.clear();
		window.draw(ball);
		window.display();
	}

	return 0;
}