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

#define SPEED 0.14

//-------------------------
//Public access members
//-------------------------

PickinSticks::PickinSticks() {
	grass.LoadSurface("grass.bmp");
	player.LoadSprite("elliot2.bmp", 32, 48);
	stick.LoadSprite("stick.bmp");

	player.SetSpriteSpeed(30);
	player.SetAnimationActive(false);
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
	}

	//character movement, only calculated when it's NOT moving
	if (player.GetMotion() == 0) {
		switch(key.keysym.sym) {
			case SDLK_UP:
				player.SetMotionY(-SPEED);
				player.SetAnimationActive(true);
				player.SetSpriteIndex(1);
				break;

			case SDLK_DOWN:
				player.SetMotionY(SPEED);
				player.SetAnimationActive(true);
				player.SetSpriteIndex(0);
				break;

			case SDLK_LEFT:
				player.SetMotionX(-SPEED);
				player.SetAnimationActive(true);
				player.SetSpriteIndex(2);
				break;

			case SDLK_RIGHT:
				player.SetMotionX(SPEED);
				player.SetAnimationActive(true);
				player.SetSpriteIndex(3);
				break;
		}
	}
}

void PickinSticks::KeyUp(SDL_KeyboardEvent const& key) {
	//character movement, only calculated when it IS moving
	if (player.GetMotion() != 0) {
		switch(key.keysym.sym) {
			case SDLK_UP:
				if (player.GetMotionY() < 0) {
					player.SetMotionY(0);
					player.SetAnimationActive(false);
				}
				break;

			case SDLK_DOWN:
				if (player.GetMotionY() > 0) {
					player.SetMotionY(0);
					player.SetAnimationActive(false);
				}
				break;

			case SDLK_LEFT:
				if (player.GetMotionX() < 0) {
					player.SetMotionX(0);
					player.SetAnimationActive(false);
				}
				break;

			case SDLK_RIGHT:
				if (player.GetMotionX() > 0) {
					player.SetMotionX(0);
					player.SetAnimationActive(false);
				}
				break;
		}
	}
}
