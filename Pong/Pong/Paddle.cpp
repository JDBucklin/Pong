#include "Paddle.h"

/**
 *	Constructor
 *	
 *	@param xPos the x position to place the paddle in the window
 *	@param yPos the y position to place the paddle in the window
 */
Paddle::Paddle(float xPos, float yPos)
{
	paddleWidth = 30;
	paddleHeight = 100;
	halfPaddleHeight = 50;
	paddleSpeed = 300;
	paddle.setSize(sf::Vector2f((float)paddleWidth, (float)paddleHeight));
	paddle.setOrigin(paddleWidth / 2.f, paddleHeight / 2.f);
	paddle.setPosition(xPos, yPos);
}

Paddle::~Paddle()
{}

/**
 *	Update the position of the paddle on the screen
 *	
 *	@param deltaTime the elapsed time since the last update
 *	@param windowHeight the height of the window to check for collisions
 */
void Paddle::update(float deltaTime, float windowHeight)
{
	if (sf::Keyboard().isKeyPressed(sf::Keyboard().Up)) {
		paddle.move(0.f, deltaTime * paddleSpeed);
		if (paddle.getPosition().y + halfPaddleHeight > windowHeight) {
			paddle.setPosition(paddle.getPosition().x, windowHeight - halfPaddleHeight);
		}
	}
	if (sf::Keyboard().isKeyPressed(sf::Keyboard().Down)) {
		paddle.move(0.f, deltaTime * -paddleSpeed);
		if (paddle.getPosition().y - halfPaddleHeight < 0) {
			paddle.setPosition(paddle.getPosition().x,  halfPaddleHeight);
		}
	}
}

/**
 *	Draws the paddle in the given window
 *	
 *	@param window the window to draw the object in
 */
void Paddle::draw(sf::RenderWindow& window)
{
	window.draw(paddle);
}

/**
 *	Returns the current position of the paddle
 *	
 *	@return a vector2f containing the x/y position of the paddle
 */
sf::Vector2f Paddle::getPosition() {
	return paddle.getPosition();
}

/**
 *	Returns the size of the paddle
 *	
 *	@return a vector2f containing the width/height of the paddle
 */
sf::Vector2f Paddle::getSize() {
	return paddle.getSize();
}