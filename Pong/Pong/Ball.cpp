#include "Ball.h"
#include <iostream>
const float PI = 3.1415926535897f;

/**
* Constructor
* 
* @param xPos the x position in the window to reset the ball to
* @param yPos the y position in the window to reset the ball to
*/
Ball::Ball(float xPos, float yPos)
{
	radius = 15.f;
	defaultSpeed = 300.f;
	currentSpeed = defaultSpeed;
	resetBall(xPos, yPos);
	ball.setRadius(radius);
	ball.setOrigin(radius, radius);
}

Ball::~Ball()
{}

/**
 * Draws the ball in the given window
 * 
 * @param window the window to draw the ball object in
 */
void Ball::draw(sf::RenderWindow& window)
{
	window.draw(ball);
}

/**
 * Resets the ball to the given coordinated within the window
 * 
 * @param xPos the x position to reset the ball to
 * @param yPos the y position to reset the ball to
 */
void Ball::resetBall(float xPos, float yPos)
{
	// Choose a random angle between 0 and 360 degrees
	// The angle needs to be in radians. The formula to
	// convert from degrees to radians is (degrees * pi)/180
	do {
		this->ballAngle = (std::rand() % 360 * PI) / 180;
	} while (std::abs(std::cos(ballAngle)) < .5);
	std::cout << ballAngle << std::endl;
	ball.setPosition(xPos, yPos);
	currentSpeed = defaultSpeed;
}

/**
 *	Updates the position of the ball in the window. This method also checks
 *	for collisions with the walls and paddles.
 *	
 *	@param deltaTime the elapsed time since the last update
 *	@param windowHeight the height of the window used for collision detection
 *	@param leftPaddle the left paddle object
 *	@param rightPaddle the rightPaddle object
 */
void Ball::updatePosition(float deltaTime, float windowHeight, Paddle& leftPaddle, Paddle& rightPaddle)
{
	// find the total distance traveled and move the ball
	float dist = currentSpeed * deltaTime;
	ball.move(std::cos(ballAngle) * dist, std::sin(ballAngle) * dist);

	//check for ball collision with walls
	//bottom of window
	if (ball.getPosition().y + radius > windowHeight) {
		ballAngle = -ballAngle;
		ball.setPosition(ball.getPosition().x, windowHeight - radius);
	}
	//top of window
	if (ball.getPosition().y - radius < 0) {
		ballAngle = -ballAngle;
		ball.setPosition(ball.getPosition().x, radius);
	}

	// check for collision with paddles
	if (paddleCollision(leftPaddle)) {
		ballAngle = PI - ballAngle;
		ball.setPosition(leftPaddle.getPosition().x + leftPaddle.getSize().x/2 + radius, ball.getPosition().y);
		currentSpeed += 75;
	} else if (paddleCollision(rightPaddle)) {
		ballAngle = PI - ballAngle;
		ball.setPosition(rightPaddle.getPosition().x - rightPaddle.getSize().x / 2 - radius, ball.getPosition().y);
		currentSpeed += 75;
	}
}

/**
 *	A method that checks for a paddle collision
 *	
 *	@param paddle the paddle to check for a collision with
 *	@return returns true if there is a paddle collision
 */
bool Ball::paddleCollision(Paddle& paddle)
{
	// abs(paddle.x (or y) - ball.x (or y) will give the distance between the
	// two objects on the given axis. If that value is greater than the minimum 
	// distance between the objects (paddle.x (or y) + radius) then there hasn't 
	// been a collision.
	if (paddle.getSize().x / 2 + this->radius < std::abs(paddle.getPosition().x - ball.getPosition().x) ||
		paddle.getSize().y / 2 + this->radius < std::abs(paddle.getPosition().y - ball.getPosition().y)) {
		return false;
	}
	return true;
}

/**
 *	Checks if the ball is past the left side of the screen
 *	
 *	@return returns true if ball past left side of screen
 */
bool Ball::isOutLeft()
{
	return ball.getPosition().x + radius < 0;
}

/**
 *	Checks if the ball is past the right side of the screen
 *	
 *	@return returns true if ball past right side of screen
 */
bool Ball::isOutRight(int windowWidth)
{
	return ball.getPosition().x - radius > windowWidth;
}
