#include "Sound.h"
namespace soundConstants{
	const int AUDIO_RATE = 22050;
	Uint16 AUDIO_FORMAT = AUDIO_S16;
	const int AUDIO_CHANNELS = 2;
	const int AUDIO_BUFFERS = 4096;
	std::string MUSIC_PATH = "content/ilwag.ogg";
	std::string COLLISION_SOUND = "content/collide.wav";
	std::string SCORE_SOUND = "content/score.wav";
}

Sound::Sound()
{
	if (Mix_OpenAudio(soundConstants::AUDIO_RATE, soundConstants::AUDIO_FORMAT, soundConstants::AUDIO_CHANNELS, soundConstants::AUDIO_BUFFERS) != 0) {
		printf("Unable to open Audio\n");
		exit(1);
	}

	_music = Mix_LoadMUS(soundConstants::MUSIC_PATH.c_str());
	_collisionSound = Mix_LoadWAV(soundConstants::COLLISION_SOUND.c_str());
	_scoreSound = Mix_LoadWAV(soundConstants::SCORE_SOUND.c_str());

	if (_music == NULL) {
		printf("Unable to load Music\n");
	}
	this->playMusic();

}


Sound::~Sound()
{
	Mix_CloseAudio();
}

void Sound::playMusic() {
	Mix_PlayMusic(this->_music, 0);
}

void Sound::playScoreSound() {
	Mix_PlayChannel(-1, this->_scoreSound, 0);
}

void Sound::playCollisionSound() {
	Mix_PlayChannel(-1, this->_collisionSound, 0);
}

void Sound::musicDone() {

	Mix_HaltMusic();
	// Mix_HaltChannel() is similar

	Mix_FreeMusic(this->_music);

	this->_music = NULL;

}