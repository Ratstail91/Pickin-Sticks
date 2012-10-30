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
	grass.LoadSurface("grass.bmp");
	player.LoadSprite("elliot2.bmp", 32, 48);
	stick.LoadSprite("stick.bmp");
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
	//draw the grass everywhere
	for (int i = 0; i < screen->w; i += grass.GetClipW()) {
		for (int j = 0; j < screen->h; j += grass.GetClipH()) {
			grass.DrawTo(screen, i, j);
		}
	}

	player.DrawTo(screen);
	stick.DrawTo(screen);
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

	//character movement, only calculated when it's not moving
	if (player.GetMotion() == 0) {
		//
	}
}

void PickinSticks::KeyUp(SDL_KeyboardEvent const& key) {
	//
}
