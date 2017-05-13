#include "Ball.h"
#include <random>
#include <ctime>
#include <cmath>

double d2r(double d) {
	return (d / 180.0) * ((double)M_PI);
}

Ball::Ball(){}
Ball::Ball(int x, int y, int ballRadius, Graphics &graphics) :
	_x(x),
	_y(y),
	_ballRadius(ballRadius)
{

	this->resetBaul();
	this->ballTexture = SDL_CreateTextureFromSurface(graphics.getRenderer(), graphics.loadImage("content/ball2.png"));
}

void Ball::draw(Graphics &graphics) {
	SDL_Rect sourceRect = { 0, 0, 45, 45 };
	SDL_Rect destRect = { this->_x - this->_ballRadius, this->_y - this->_ballRadius, 2 * this->_ballRadius, 2 * this->_ballRadius };

	graphics.blitSurface(this->ballTexture, &sourceRect, &destRect);
}

void Ball::update(Paddle pad, Score &score) {
	//	Upper and Lower wall collision check :
	if (this->_y - entityConstants::newBallRadius < 0) {
		this->_y = entityConstants::newBallRadius;
		this->changeYdir();
	}
	else if (this->_y + entityConstants::newBallRadius > globals::SCREEN_HEIGHT) {
		this->_y = globals::SCREEN_HEIGHT - entityConstants::newBallRadius;
		this->changeYdir();
	}
	
	// Paddle collisions check : 

	// Colliding from right
	if (this->_x - entityConstants::newBallRadius < (pad.getX() + entityConstants::PaddleCollConstantW) &&
		this->_x + entityConstants::newBallRadius >(pad.getX() + entityConstants::PaddleCollConstantW) &&
		this->_y > pad.getY() - entityConstants::PADDLE_LENGTH / 2 &&
		this->_y < pad.getY() + entityConstants::PADDLE_LENGTH / 2)
	{
		this->_x = pad.getX() + (entityConstants::PaddleCollConstantW + entityConstants::newBallRadius);
		this->changeXdir();

		this->accelerateBallAlongY(pad.getVelocity());
	}

	// Colliding from left
	else if (this->_x + entityConstants::newBallRadius >(pad.getX() - entityConstants::PaddleCollConstantW) &&
		this->_x - entityConstants::newBallRadius < (pad.getX() - entityConstants::PaddleCollConstantW) &&
		this->_y > pad.getY() - entityConstants::PaddleCollConstantL &&
		this->_y < pad.getY() + entityConstants::PaddleCollConstantL)
	{
		this->_x = pad.getX() - entityConstants::PaddleCollConstantW - entityConstants::newBallRadius;
		this->changeXdir();
		this->accelerateBallAlongY(pad.getVelocity());
	}
	
	// Colliding from up
	else if (this->_x > pad.getX() - entityConstants::PaddleCollConstantW &&
		this->_x < pad.getX() + entityConstants::PaddleCollConstantW &&
		this->_y + entityConstants::newBallRadius > pad.getY() - entityConstants::PaddleCollConstantL &&
		this->_y - entityConstants::newBallRadius < pad.getY() - entityConstants::PaddleCollConstantL )
	{
		this->_y = pad.getY() - entityConstants::PaddleCollConstantL - entityConstants::newBallRadius;
		this->changeYdir();

		this->accelerateBallAlongY(pad.getVelocity());
	}

	// Colliding from down
	else if (this->_x > pad.getX() - entityConstants::PaddleCollConstantW &&
		this->_x < pad.getX() + entityConstants::PaddleCollConstantW &&
		this->_y - entityConstants::newBallRadius < pad.getY() + entityConstants::PaddleCollConstantL &&
		this->_y + entityConstants::newBallRadius > pad.getY() + entityConstants::PaddleCollConstantL)
	{
		this->_y = pad.getY() + entityConstants::PaddleCollConstantL + entityConstants::newBallRadius;
		this->changeYdir();

		this->accelerateBallAlongY(pad.getVelocity());
	}



	// Right player scores
	if (this->_x + entityConstants::newBallRadius < 0) {
		score.rightScores();
		this->resetBaul();
	}
	// Left Player Scores
	else if (this->_x - entityConstants::newBallRadius > globals::SCREEN_WIDTH) {
		score.leftScores();
		this->resetBaul();
	}

	this->_x += this->_dx;
	this->_y += this->_dy;
}

void Ball::changeYdir() {
	this->_dy = -this->_dy;
}

void Ball::changeXdir() {
	this->_dx = -this->_dx;
}

void Ball::resetBaul() {
	std::default_random_engine get(time(0));
	std::uniform_int_distribution<int> leftOrRight(0, 1);

	int angle = 0;
	int velocity = entityConstants::BALL_VELOCITY;

	if (leftOrRight(get)) {
		std::uniform_int_distribution<int> towardsRight(-60, 60);
		angle = towardsRight(get);
	}
	else {
		std::uniform_int_distribution<int> towardsLeft(120, 240);
		angle = towardsLeft(get);
	}

	this->_dx = cos(d2r(angle)) * velocity;
	this->_dy = sin(d2r(angle)) * velocity;
	this->_x = globals::SCREEN_WIDTH / 2;
	this->_y = globals::SCREEN_HEIGHT / 2;

}

void Ball::accelerateBallAlongY(int velAlongY) {
	_dy += velAlongY;
	if (_dy > entityConstants::MAX_BALL_Y_VEL) {
		_dy = entityConstants::MAX_BALL_Y_VEL;
	} 
	else if (_dy < -entityConstants::MAX_BALL_Y_VEL) {
			_dy = -entityConstants::MAX_BALL_Y_VEL;
		}
}