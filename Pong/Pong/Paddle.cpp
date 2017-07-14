#include "Paddle.h"

Paddle::Paddle(float xPos, float yPos)
{
	paddle.setSize(sf::Vector2f(paddleWidth, paddleHeight));
	paddle.setOrigin(paddleWidth / 2, paddleHeight / 2);
	paddle.setPosition(xPos, yPos);
}

Paddle::~Paddle()
{}

void Paddle::update(float deltaTime, float windowHeight)
{
	if (sf::Keyboard().isKeyPressed(sf::Keyboard().Up)) {
		paddle.move(0.f, deltaTime * paddleSpeed);
	}
	if (sf::Keyboard().isKeyPressed(sf::Keyboard().Down)) {
		paddle.move(0.f, deltaTime * -paddleSpeed);
	}
}

void Paddle::draw(sf::RenderWindow& window)
{
	window.draw(paddle);
}

sf::Vector2f Paddle::getPosition() {
	return paddle.getPosition();
}

sf::Vector2f Paddle::getSize() {
	return paddle.getSize();
}