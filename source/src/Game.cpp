#include "Game.h"

Game::Game() {
	SDL_Init(SDL_INIT_EVERYTHING);

	this->gameLoop();
}

Game::~Game() {
	TTF_Quit();
	SDL_Quit();
}


void Game::gameLoop() {
	SDL_Event ev;
	Graphics graphics;
	Input input;


	// Setting up entities for the game : 
	this->_ball = Ball(globals::SCREEN_WIDTH / 2, globals::SCREEN_WIDTH / 2, entityConstants::BALL_RADIUS, graphics);
	this->_paddle1 = Paddle(entityConstants::PADDLE1POSITION_X, globals::SCREEN_HEIGHT / 2, 
		entityConstants::PADDLE_LENGTH, entityConstants::PADDLE_WIDTH, graphics);
	this->_paddle2 = Paddle(entityConstants::PADDLE2POSITION_X, globals::SCREEN_HEIGHT / 2,
		entityConstants::PADDLE_LENGTH, entityConstants::PADDLE_WIDTH, graphics);
	//------------------------------------


	bool game_is_running = true;
	int next_game_tick = SDL_GetTicks();
	int loops = 0;

/*	// For counting framerate per second
	int fps = 0;
	int tick = 0;
*/	//----------------------------------

	while (game_is_running) {
		
		// Input handling. 
		// Could be more neat using switch cases but ehhh.....just want to finish this asap. So happy I know SDL now. :)
		input.beginNewFrame();

		if(SDL_PollEvent(&ev)) {
			if (ev.type == SDL_QUIT) {
				game_is_running = false;
			}
			else if (ev.type == SDL_KEYDOWN) {
				if (ev.key.repeat == 0) {
					input.keyPressed(ev);
				}
			}
			else if (ev.type == SDL_KEYUP) {
				if (ev.key.repeat == 0) {
					input.keyReleased(ev);
				}
			}
		}
		
		if (input.wasKeyHeld(SDL_SCANCODE_UP) == true) {
			_paddle1.moveUp();
		}
		else if (input.wasKeyHeld(SDL_SCANCODE_DOWN) == true) {
			_paddle1.moveDown();
		}
		else {
			_paddle1.stopMoving();
		}
		if (input.wasKeyHeld(SDL_SCANCODE_W) == true) {
			_paddle2.moveUp();
		}
		else if (input.wasKeyHeld(SDL_SCANCODE_S) == true) {
			_paddle2.moveDown();
		}
		else {
			_paddle2.stopMoving();
		}
		//===============================================



		// Code to get maximum framerate with constant x (fps) update(); x = 60 here. THANK YOU DeWitter.
		loops = 0;
		while (SDL_GetTicks() > next_game_tick && loops < globals::MAX_FRAME_SKIP) {
			
			this->update();
			
			next_game_tick += globals::SKIP_TICKS;
			loops++;
		}
		
		this->draw(graphics);


	/*	// my method to count framerate per second
		if (SDL_GetTicks() > tick) {
			printf("frames-per-second:%d\n", fps);
			fps = 0;
			tick += 1000;
		}
		fps++;
	*/	//----------------------------------------


	//	End of actual loop
	//	printf("%s\n", SDL_GetError());
	}
}

void Game::draw(Graphics &graphics){

	graphics.clear();

	this->_ball.draw(graphics);
	this->_paddle1.draw(graphics);
	this->_paddle2.draw(graphics);
	this->score.draw(graphics);

	graphics.flip();
}
void Game::update() {
	// half the work only
	(_ball.getX() < globals::SCREEN_WIDTH / 2) ?
		this->_ball.update(_paddle1, this->score, this->sound) :
		this->_ball.update(_paddle2, this->score, this->sound);

	this->_paddle1.update();
	this->_paddle2.update();
}