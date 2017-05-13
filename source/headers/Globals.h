#include <string>
#include <map>

#pragma once

namespace globals{

	const int SCREEN_WIDTH = 800;
	const int SCREEN_HEIGHT = 600;
	const int FPS = 80;
	const int SKIP_TICKS = 1000 / FPS;
	const int MAX_FRAME_SKIP = 5;

}

namespace entityConstants{
	const int BALL_VELOCITY = 6;
	const int MAX_BALL_Y_VEL = 7;
	const int PADDLE_SPEED = 4;
	const int PADDLE_LENGTH = 100;
	const int PADDLE_WIDTH = 50;
	const int PADDLE1POSITION_X = 10;
	const int PADDLE2POSITION_X = globals::SCREEN_WIDTH - PADDLE1POSITION_X;
	const int BALL_RADIUS = 15;
	const int SCORE_PLACEMENT_X = 40;
	const int SCORE_WIDTH = 90;
	const int SCORE_HEIGHT = 30;
	const int SCORE_FONT_SIZE = 25;
	// Because my sprites shine, I can't put exact position of pixel in image for collision. 
	// This averages it out. So the collision looks decent enough, never perfect.
	const int newBallRadius = entityConstants::BALL_RADIUS / 1.5;
	const int PaddleCollConstantW = entityConstants::PADDLE_WIDTH / 8;
	const int PaddleCollConstantL = entityConstants::PADDLE_LENGTH / 2;
}