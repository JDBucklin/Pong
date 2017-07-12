#pragma once
#include <SFML/Graphics.hpp>

class Ball
{
public:
	Ball(float xPos, float yPos);
	~Ball();
	void draw(sf::RenderWindow& window);
	void resetBall(float xPos, float yPos);
	void updatePosition(float deltaTime, float windowHeight);
	bool isOutLeft();
	bool isOutRight(int windowWidth);
private:
	sf::CircleShape ball;
	float radius;
	float speed;
	float ballAngle;
};

