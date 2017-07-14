#pragma once
#include <SFML/Graphics.hpp>
#include "Paddle.h"

class Ball
{
public:
	Ball(float xPos, float yPos);
	~Ball();
	void draw(sf::RenderWindow& window);
	void resetBall(float xPos, float yPos);
	void updatePosition(float deltaTime, float windowHeight, Paddle& leftPaddle, Paddle& rightPaddle);
	bool paddleCollision(Paddle& paddle);
	bool isOutLeft();
	bool isOutRight(int windowWidth);
private:
	sf::CircleShape ball;
	float radius;
	float currentSpeed;
	float defaultSpeed;
	float ballAngle;
};

