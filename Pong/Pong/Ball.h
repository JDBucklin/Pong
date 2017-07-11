#pragma once
#include <SFML/Graphics.hpp>

class Ball
{
public:
	Ball(float xPos, float yPos);
	~Ball();
	void draw(sf::RenderWindow& window);
	void resetAngle();
	void updatePosition(float deltaTime, float width, float height);
private:
	sf::CircleShape ball;
	float radius;
	float speed;
	float ballAngle;
};

