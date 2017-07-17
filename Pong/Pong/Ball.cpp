#include "Ball.h"
#include <iostream>
const float PI = 3.1415926535897f;

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

void Ball::draw(sf::RenderWindow& window)
{
	window.draw(ball);
}

void Ball::resetBall(float xPos, float yPos)
{
	// Choose a random angle between 0 and 360 degrees
	// The angle needs to be in radians. The forumula to
	// convert from degrees to radians is (degrees * pi)/180
	do {
		this->ballAngle = (std::rand() % 360 * PI) / 180;
	} while (std::abs(std::cos(ballAngle)) < .5);
	std::cout << ballAngle << std::endl;
	ball.setPosition(xPos, yPos);
	currentSpeed = defaultSpeed;
}

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

bool Ball::paddleCollision(Paddle& paddle)
{
	if (paddle.getSize().x / 2 + this->radius < std::abs(paddle.getPosition().x - ball.getPosition().x) ||
		paddle.getSize().y / 2 + this->radius < std::abs(paddle.getPosition().y - ball.getPosition().y)) {
		return false;
	}
	return true;
}

bool Ball::isOutLeft()
{
	return ball.getPosition().x + radius < 0;
}

bool Ball::isOutRight(int windowWidth)
{
	return ball.getPosition().x - radius > windowWidth;
}
