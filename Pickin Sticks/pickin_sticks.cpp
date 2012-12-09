/* File Name: pickin_sticks.cpp
 * Author: Kayne Ruse
 * Date (dd/mm/yyyy): 31/10/2012
 * Copyright: ...
 * Description: ...
*/
#include "pickin_sticks.h"

#include "delta.h"

#include <iostream>
using namespace std;

#define CHAR_SPEED 0.14

//-------------------------
//Public access members
//-------------------------

PickinSticks::PickinSticks() {
	grass.LoadSurface("grass.bmp");
	player.LoadSprite("elliot2.bmp", 32, 48);
	stick.LoadSprite("stick.bmp");

	player.SetSpriteSpeed(20);
	player.SetAnimationActive(true);
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
	Delta::CalcDelta();

	//update all actors
	player.Update(Delta::GetDelta());
	stick.Update(Delta::GetDelta());
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

		//character motion
		case SDLK_UP:
			player.ShiftMotionY(-CHAR_SPEED);
			break;

		case SDLK_DOWN:
			player.ShiftMotionY(CHAR_SPEED);
			break;

		case SDLK_LEFT:
			player.ShiftMotionX(-CHAR_SPEED);
			break;

		case SDLK_RIGHT:
			player.ShiftMotionX(CHAR_SPEED);
			break;
	}
}

void PickinSticks::KeyUp(SDL_KeyboardEvent const& key) {
	//character motion
	switch(key.keysym.sym) {
		case SDLK_UP:
			if (player.GetMotionY() + CHAR_SPEED <= CHAR_SPEED)
				player.ShiftMotionY(CHAR_SPEED);
			break;

		case SDLK_DOWN:
			if (player.GetMotionY() - CHAR_SPEED >= -CHAR_SPEED)
				player.ShiftMotionY(-CHAR_SPEED);
			break;

		case SDLK_LEFT:
			if (player.GetMotionX() + CHAR_SPEED <= CHAR_SPEED)
				player.ShiftMotionX(CHAR_SPEED);
			break;

		case SDLK_RIGHT:
			if (player.GetMotionX() - CHAR_SPEED >= -CHAR_SPEED)
				player.ShiftMotionX(-CHAR_SPEED);
			break;
	}
}
