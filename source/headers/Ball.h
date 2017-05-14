#include "Graphics.h"
#include "Paddle.h"
#include "Score.h"
#include "Sound.h"

#pragma once
class Ball
{
public:
	Ball();
	Ball(float x, float y, int ballRadius, Graphics &graphics);
	
	void draw(Graphics &graphics);
	void update(Paddle pad, Score &score, Sound &sound);

	void resetBaul();
	float getX() { return this->_x; }
private:
	SDL_Texture* ballTexture;
	float _x;
	float _y;
	float _dx;
	float _dy;
	int _ballRadius;

	void accelerateBallAlongY(float velAlongY);
	void changeYdir(Sound &sound);
	void changeXdir(Sound &sound);
};

