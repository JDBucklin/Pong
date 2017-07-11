#include "Ball.h"
#include <iostream>
const float PI = 3.1415926535897f;

Ball::Ball(float xPos, float yPos)
{
	std::srand((unsigned int)time(NULL));
	radius = 10.f;
	speed = 100.f;
	resetAngle();
	ball.setRadius(radius);
	ball.setOrigin(radius, radius);
	ball.setPosition(xPos, yPos);
}

Ball::~Ball()
{
}

void Ball::draw(sf::RenderWindow& window)
{
	window.draw(this->ball);
}

void Ball::resetAngle()
{
	// Choose a random angle between 0 and 360 degrees
	// The angle needs to be in radians. The forumula to
	// convert from degrees to radians is (degrees * pi)/180
	do {
		this->ballAngle = (std::rand() % 360 * PI) / 180;
	} while (this->ballAngle == 0);
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
}
