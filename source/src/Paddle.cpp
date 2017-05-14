#include "Paddle.h"


Paddle::Paddle(){}

Paddle::Paddle(int x, int y, int length, int breadth, Graphics &graphics) :
		_x(x),
		_y(y),
		_length(length),
		_breadth(breadth),
		_dy(0)
{
	this->paddleTexture = SDL_CreateTextureFromSurface(graphics.getRenderer(), graphics.loadImage("content/padd.png"));
}

void Paddle::draw(Graphics &graphics) {
	SDL_Rect sourceRect = { 0, 0, 100, 400 };
	SDL_Rect destRect = { this->_x - (this->_breadth) / 2, this->_y - (this->_length) / 2, this->_breadth, this->_length };
	graphics.blitSurface(this->paddleTexture, &sourceRect, &destRect);
}

void Paddle::update() {
	
	this->_y += this->_dy;
	if (this->_y - entityConstants::PaddleCollConstantL < 0) {
		this->_y = entityConstants::PaddleCollConstantL;
	}
	if (this->_y + entityConstants::PaddleCollConstantL > globals::SCREEN_HEIGHT) {
		this->_y = globals::SCREEN_HEIGHT - entityConstants::PaddleCollConstantL;
	}
}

void Paddle::moveUp() {
	this->_dy = -entityConstants::PADDLE_SPEED;
}
void Paddle::moveDown() {
	this->_dy = entityConstants::PADDLE_SPEED;
}
void Paddle::stopMoving(){
	this->_dy = 0;
}