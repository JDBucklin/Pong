#pragma once
class Game
{
public:
	Game();
	~Game();
	void play();
private:
	//Game variables
	int windowHeight = 400;
	int windowWidth = 800;
	float ballRadius = 10.f;
	float switchTime = 1.f / 30.f;
};

