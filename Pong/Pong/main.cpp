#include <iostream>
#include "Game.h"

int main() {
	std::srand((unsigned int)time(NULL));
	Game pong;
	pong.play();
	return 0;
}