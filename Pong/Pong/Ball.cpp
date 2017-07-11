#include "Ball.h"
#include <iostream>
const float PI = 3.1415926535897f;

Ball::Ball(float xPos, float yPos)
{
	std::srand((unsigned int)time(NULL));
	radius = 15.f;
	speed = 300.f;
	resetBall(xPos, yPos);
	ball.setRadius(radius);
	ball.setOrigin(radius, radius);
}

Ball::~Ball()
{
}

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
	} while (std::abs(std::cos(ballAngle)) < .8);
	std::cout << ballAngle << std::endl;
	ball.setPosition(xPos, yPos);
}

void Ball::updatePosition(float deltaTime, float height, float width)
{
	// find the total distance traveled and move the ball
	float dist = speed * deltaTime;
	ball.move(std::cos(ballAngle) * dist, std::sin(ballAngle) * dist);

	//check for ball collision
	//bottom of window
	if (ball.getPosition().y + radius > height) {
		ballAngle = -ballAngle;
		ball.setPosition(ball.getPosition().x, height - radius);
	}
	//top of window
	if (ball.getPosition().y - radius < 0) {
		ballAngle = -ballAngle;
		ball.setPosition(ball.getPosition().x, radius);
	}
	//past left side of window right player scores
	if (ball.getPosition().x + radius < 0) {
		resetBall(width / 2, height / 2);
	}
	//past right side of window left player scores
	if (ball.getPosition().x - radius > width) {
		resetBall(width / 2, height / 2);
	}
}
