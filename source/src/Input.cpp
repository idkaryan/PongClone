#include "Input.h"

void Input::beginNewFrame() {
	this->_pressedKeys.clear();
	this->_releasedKeys.clear();
}
void Input::keyPressed(SDL_Event &ev) {
	this->_pressedKeys[ev.key.keysym.scancode] = true;
	this->_heldKeys[ev.key.keysym.scancode] = true;
}

void Input::keyReleased(SDL_Event &ev) {
	this->_releasedKeys[ev.key.keysym.scancode] = true;
	this->_heldKeys[ev.key.keysym.scancode] = false;
}

bool Input::wasKeyPressed(SDL_Scancode code) {
	return this->_pressedKeys[code];
}
bool Input::wasKeyReleased(SDL_Scancode code) {
	return this->_releasedKeys[code];
}
bool Input::wasKeyHeld(SDL_Scancode code) {
	return this->_heldKeys[code];
}