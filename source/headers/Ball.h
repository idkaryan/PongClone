#include "Graphics.h"
#include "Paddle.h"
#include "Score.h"

#pragma once
class Ball
{
public:
	Ball();
	Ball(int x, int y, int ballRadius, Graphics &graphics);
	
	void draw(Graphics &graphics);
	void update(Paddle pad, Score &score);

	void resetBaul();
	int getX() { return this->_x; }
private:
	SDL_Texture* ballTexture;
	int _x;
	int _y;
	int _dx;
	int _dy;
	int _ballRadius;

	void accelerateBallAlongY(int velAlongY);
	void changeYdir();
	void changeXdir();
};

