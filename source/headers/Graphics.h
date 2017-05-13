#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include "Globals.h"

#pragma once
class Graphics
{
public:
	Graphics();
	~Graphics();
	SDL_Surface* loadImage(const std::string &filePath);
	void blitSurface(SDL_Texture*, SDL_Rect* sourceRect, SDL_Rect* DestRect);
	void flip();
	void clear();
	SDL_Renderer* Graphics::getRenderer() const;
private:
	SDL_Window* _window;
	SDL_Renderer* _renderer;

	std::map<std::string, SDL_Surface*> _spriteSheets;
};

