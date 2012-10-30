/* File Name: pickin_sticks.cpp
 * Author: Kayne Ruse
 * Date (dd/mm/yyyy): 31/10/2012
 * Copyright: ...
 * Description: ...
*/
#include "pickin_sticks.h"

//-------------------------
//Public access members
//-------------------------

PickinSticks::PickinSticks() {
	//
}

PickinSticks::~PickinSticks() {
	//
}

//-------------------------
//Frame loop
//-------------------------

void PickinSticks::FrameStart() {
	//
}

void PickinSticks::FrameEnd() {
	//
}

void PickinSticks::Update() {
	//
}

void PickinSticks::Render(SDL_Surface* const screen) {
	//
}

//-------------------------
//Event handlers
//-------------------------

void PickinSticks::MouseMotion(SDL_MouseMotionEvent const& motion) {
	//
}

void PickinSticks::MouseButtonDown(SDL_MouseButtonEvent const& button) {
	//
}

void PickinSticks::MouseButtonUp(SDL_MouseButtonEvent const& button) {
	//
}

void PickinSticks::KeyDown(SDL_KeyboardEvent const& key) {
	switch(key.keysym.sym) {
		case SDLK_ESCAPE:
			QuitEvent();
			break;
	}
}

void PickinSticks::KeyUp(SDL_KeyboardEvent const& key) {
	//
}
