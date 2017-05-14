#include "Graphics.h"
#include"Sound.h"
#include "Input.h"
#include "Ball.h"
#include "Paddle.h"
#include "Score.h"

// The game class - Logic how graphics, input, sound and the game happens.

#pragma once
class Game
{
public:
	Game();
	~Game();

private:
	// The main gameloop for the game
	void gameLoop();
	void draw(Graphics &graphics);
	void update();

	Ball _ball;
	Paddle _paddle1;
	Paddle _paddle2;
	Score score;
	Sound sound;
};

