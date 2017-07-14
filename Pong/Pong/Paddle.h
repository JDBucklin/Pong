#pragma once
#include <SFML/Graphics.hpp>
class Paddle
{
public:
	Paddle(float xPos, float yPos);
	~Paddle();
	void update(float deltaTime, float windowHeight);
	void draw(sf::RenderWindow& window);
	sf::Vector2f getPosition();
	sf::Vector2f getSize();
private:
	sf::RectangleShape paddle;
	int paddleWidth = 30;
	int paddleHeight = 100;
	int halfPaddleHeight = 50;
	float paddleSpeed = 300;
};

