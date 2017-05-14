#include "Graphics.h";
#include <SDL/SDL_mixer.h>

#pragma once
class Sound
{
public:
	Sound();
	~Sound();

	void playMusic();
	void musicDone();
	void playScoreSound();
	void playCollisionSound();
private:

	Mix_Music* _music;
	Mix_Chunk* _scoreSound;
	Mix_Chunk* _collisionSound;
};

