#include "Score.h"


Score::Score() :
scoreLeft(0),
scoreRight(0)
{
	if (TTF_Init() == -1) {
		printf("TTF_Init: %s\n", TTF_GetError());
		exit(2);
	}

	this->scoreFont = TTF_OpenFont("content/dsb.ttf", entityConstants::SCORE_FONT_SIZE);
}
Score::Score(int x, int y) {
	scoreLeft += x;
	scoreRight += y;
}

void Score::leftScores() { 
	this->scoreLeft++; 
}

void Score::rightScores() { 
	this->scoreRight++; 
}

void Score::resetScore() {
	this->scoreRight = 0;
	this->scoreLeft = 0;
}

void Score::draw(Graphics &graphics) {
	SDL_Color color = { 255, 255, 255 };
	std::string leftScoreString = "Score : " + std::to_string(this->getLeftScore());
	std::string rightScoreString = "Score : " + std::to_string(this->getRightScore());
	SDL_Surface* leftScoreSurface = TTF_RenderText_Solid(this->scoreFont, leftScoreString.c_str(), color);
	SDL_Surface* rightScoreSurface = TTF_RenderText_Solid(this->scoreFont, rightScoreString.c_str(), color);
	SDL_Rect destRectLeft = 
	{ entityConstants::SCORE_PLACEMENT_X, 40, entityConstants::SCORE_WIDTH, entityConstants::SCORE_HEIGHT };
	SDL_Rect destRectRight = 
	{ globals::SCREEN_WIDTH - 2 * entityConstants::SCORE_PLACEMENT_X - 60, 40, entityConstants::SCORE_WIDTH, entityConstants::SCORE_HEIGHT };
	
	this->leftScoreTexture = SDL_CreateTextureFromSurface(graphics.getRenderer(), leftScoreSurface);
	this->rightScoreTexture = SDL_CreateTextureFromSurface(graphics.getRenderer(), rightScoreSurface);

	graphics.blitSurface(leftScoreTexture, NULL, &destRectLeft);
	graphics.blitSurface(rightScoreTexture, NULL, &destRectRight);

	SDL_FreeSurface(leftScoreSurface);
	SDL_FreeSurface(rightScoreSurface);
	SDL_DestroyTexture(leftScoreTexture);
	SDL_DestroyTexture(rightScoreTexture);
}