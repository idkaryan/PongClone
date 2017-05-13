#include "Graphics.h";
#include "Globals.h"


#pragma once

class Paddle
{
public:
	Paddle();
	Paddle(int x, int y, int length, int breadth, Graphics &graphics);

	void draw(Graphics &graphics);
	void update();

	void moveUp();
	void moveDown();
	void stopMoving();

	int getX() { return this->_x; }
	int getY() { return this->_y; }
	int getVelocity() { return this->_dy; }

private:
	int _breadth;
	int _length;
	int _dy;
	int _x;
	int _y;
	SDL_Texture* paddleTexture;
};

