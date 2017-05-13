#include "Globals.h"
#include <SDL\SDL.h>

#pragma once
class Input
{
public:
	void beginNewFrame();
	void keyPressed(SDL_Event &ev);
	void keyReleased(SDL_Event &ev);
	bool wasKeyPressed(SDL_Scancode code);
	bool wasKeyReleased(SDL_Scancode code);
	bool wasKeyHeld(SDL_Scancode code);

private:
	std::map<SDL_Scancode, bool> _pressedKeys;
	std::map<SDL_Scancode, bool> _releasedKeys;
	std::map<SDL_Scancode, bool> _heldKeys;
};

