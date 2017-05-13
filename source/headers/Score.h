#include "Graphics.h"
#include <string>

#pragma once
class Score
{
public:
	Score();
	Score::Score(int x, int y);

	int getLeftScore() { return this->scoreLeft; }
	int getRightScore() { return this->scoreRight; }

	void leftScores();
	void rightScores();
	void resetScore();
	void draw(Graphics &graphics);

	TTF_Font* scoreFont;

private:
	int scoreLeft;
	int scoreRight;
	SDL_Texture* leftScoreTexture;
	SDL_Texture* rightScoreTexture;
};

